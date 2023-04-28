/*
 * Check decoding of netlink protocol.
 *
 * Copyright (c) 2014-2016 Dmitry V. Levin <ldv@altlinux.org>
 * Copyright (c) 2016 Fabien Siron <fabien.siron@epita.fr>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "tests.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <linux/netlink.h>
#include <linux/sock_diag.h>
#include <linux/netlink_diag.h>

#if !defined NETLINK_SOCK_DIAG && defined NETLINK_INET_DIAG
# define NETLINK_SOCK_DIAG NETLINK_INET_DIAG
#endif

static void
send_query(const int fd)
{
	static const struct req {
		struct nlmsghdr nlh;
		const char magic[4];
	} c_req = {
		.nlh = {
			.nlmsg_len = sizeof(struct req),
			.nlmsg_type = NLMSG_NOOP,
			.nlmsg_flags = NLM_F_DUMP | NLM_F_REQUEST
		},
		.magic = "abcd"
	};
	struct req *const req = tail_memdup(&c_req, sizeof(c_req));

	/* zero address */
	if (sendto(fd, NULL, sizeof(*req), MSG_DONTWAIT, NULL, 0) != -1)
		perror_msg_and_skip("sendto");

	printf("sendto(%d, NULL, %u, MSG_DONTWAIT, NULL, 0) = -1 %s (%m)\n",
	       fd, (unsigned) sizeof(*req), errno2name());

	/* zero length */
	if (sendto(fd, req, 0, MSG_DONTWAIT, NULL, 0) != 0)
		perror_msg_and_skip("sendto");

	printf("sendto(%d, \"\", 0, MSG_DONTWAIT, NULL, 0) = 0\n", fd);

	/* zero address and length */
	if (sendto(fd, NULL, 0, MSG_DONTWAIT, NULL, 0) != 0)
		perror_msg_and_skip("sendto");

	printf("sendto(%d, NULL, 0, MSG_DONTWAIT, NULL, 0) = 0\n", fd);

	/* unfetchable struct nlmsghdr */
	const void *const efault = tail_alloc(sizeof(struct nlmsghdr) - 1);
	sendto(fd, efault, sizeof(struct nlmsghdr), MSG_DONTWAIT, NULL, 0);

	printf("sendto(%d, %p, %u, MSG_DONTWAIT, NULL, 0) = -1 EFAULT (%m)\n",
	       fd, efault, (unsigned) sizeof(struct nlmsghdr));

	/* whole message length < sizeof(struct nlmsghdr) */
	if (sendto(fd, req->magic, sizeof(req->magic), MSG_DONTWAIT, NULL, 0)
	    != (unsigned) sizeof(req->magic))
		perror_msg_and_skip("sendto");

	printf("sendto(%d, \"abcd\", %u, MSG_DONTWAIT, NULL, 0) = %u\n",
	       fd, (unsigned) sizeof(req->magic), (unsigned) sizeof(req->magic));

	/* a single message with some data */
	if (sendto(fd, req, sizeof(*req), MSG_DONTWAIT, NULL, 0) !=
	    (unsigned) sizeof(*req))
		perror_msg_and_skip("sendto");

	printf("sendto(%d, {{len=%u, type=NLMSG_NOOP, flags=NLM_F_REQUEST|0x%x"
	       ", seq=0, pid=0}, \"abcd\"}, %u, MSG_DONTWAIT, NULL, 0) = %u\n",
	       fd, req->nlh.nlmsg_len, NLM_F_DUMP,
	       (unsigned) sizeof(*req), (unsigned) sizeof(*req));

	/* a single message without data */
	req->nlh.nlmsg_len = sizeof(req->nlh);

	if (sendto(fd, &req->nlh, sizeof(req->nlh), MSG_DONTWAIT, NULL, 0)
	    != (unsigned) sizeof(req->nlh))
		perror_msg_and_skip("sendto");

	printf("sendto(%d, {{len=%u, type=NLMSG_NOOP, flags=NLM_F_REQUEST|0x%x"
	       ", seq=0, pid=0}}, %u, MSG_DONTWAIT, NULL, 0) = %u\n",
	       fd, req->nlh.nlmsg_len, NLM_F_DUMP,
	       (unsigned) sizeof(req->nlh), (unsigned) sizeof(req->nlh));

	/* nlmsg_len > whole message length */
	req->nlh.nlmsg_len = sizeof(*req) + 8;
	if (sendto(fd, req, sizeof(*req), MSG_DONTWAIT, NULL, 0) !=
	    (unsigned) sizeof(*req))
		perror_msg_and_skip("sendto");

	printf("sendto(%d, {{len=%u, type=NLMSG_NOOP, flags=NLM_F_REQUEST|0x%x"
	       ", seq=0, pid=0}, \"abcd\"}, %u, MSG_DONTWAIT, NULL, 0) = %u\n",
	       fd, req->nlh.nlmsg_len, NLM_F_DUMP,
	       (unsigned) sizeof(*req), (unsigned) sizeof(*req));
}

int main(void)
{
	struct sockaddr_nl addr;
	socklen_t len = sizeof(addr);
	int fd;

	memset(&addr, 0, sizeof(addr));
	addr.nl_family = AF_NETLINK;

	if ((fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_SOCK_DIAG)) == -1)
		perror_msg_and_skip("socket AF_NETLINK");

	printf("socket(AF_NETLINK, SOCK_RAW, NETLINK_SOCK_DIAG) = %d\n",
	       fd);
	if (bind(fd, (struct sockaddr *) &addr, len))
		perror_msg_and_skip("bind");
	printf("bind(%d, {sa_family=AF_NETLINK, nl_pid=0, nl_groups=00000000}"
	       ", %u) = 0\n", fd, len);

	send_query(fd);

	printf("+++ exited with 0 +++\n");

	return 0;
}
