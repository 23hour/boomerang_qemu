/** @file
  Supporting functions for X64 architecture.

  Copyright (c) 2010 - 2013, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "DebugAgent.h"

/**
  Initialize IDT entries to support source level debug.

**/
VOID
InitializeDebugIdt (
  VOID
  )
{
  IA32_IDT_GATE_DESCRIPTOR   *IdtEntry;
  UINTN                      InterruptHandler;
  IA32_DESCRIPTOR            IdtDescriptor;
  UINTN                      Index;
  UINT16                     CodeSegment;

  AsmReadIdtr (&IdtDescriptor);

  //
  // Use current CS as the segment selector of interrupt gate in IDT
  //
  CodeSegment = AsmReadCs ();

  IdtEntry = (IA32_IDT_GATE_DESCRIPTOR *) IdtDescriptor.Base;

  for (Index = 0; Index < 20; Index ++) {
    if (((PcdGet32 (PcdExceptionsIgnoredByDebugger) & ~(BIT1 | BIT3)) & (1 << Index)) != 0) {
      //
      // If the exception is masked to be reserved except for INT1 and INT3, skip it
      //
      continue;
    }
    InterruptHandler = (UINTN)&Exception0Handle + Index * ExceptionStubHeaderSize;
    IdtEntry[Index].Bits.OffsetLow       = (UINT16)(UINTN)InterruptHandler;
    IdtEntry[Index].Bits.OffsetHigh      = (UINT16)((UINTN)InterruptHandler >> 16);
    IdtEntry[Index].Bits.OffsetUpper     = (UINT32)((UINTN)InterruptHandler >> 32);
    IdtEntry[Index].Bits.Selector        = CodeSegment;
    IdtEntry[Index].Bits.GateType        = IA32_IDT_GATE_TYPE_INTERRUPT_32;
  }

  InterruptHandler = (UINTN) &TimerInterruptHandle;
  IdtEntry[DEBUG_TIMER_VECTOR].Bits.OffsetLow       = (UINT16)(UINTN)InterruptHandler;
  IdtEntry[DEBUG_TIMER_VECTOR].Bits.OffsetHigh      = (UINT16)((UINTN)InterruptHandler >> 16);
  IdtEntry[DEBUG_TIMER_VECTOR].Bits.OffsetUpper     = (UINT32)((UINTN)InterruptHandler >> 32);
  IdtEntry[DEBUG_TIMER_VECTOR].Bits.Selector        = CodeSegment;
  IdtEntry[DEBUG_TIMER_VECTOR].Bits.GateType        = IA32_IDT_GATE_TYPE_INTERRUPT_32;

  //
  // Set DE flag in CR4 to enable IO breakpoint
  //
  AsmWriteCr4 (AsmReadCr4 () | BIT3);
}

/**
  Retrieve exception handler from IDT table by ExceptionNum.

  @param[in]  ExceptionNum    Exception number
 
  @return Exception handler

**/
VOID *
GetExceptionHandlerInIdtEntry (
  IN UINTN             ExceptionNum
  )
{
  IA32_IDT_GATE_DESCRIPTOR   *IdtEntry;
  IA32_DESCRIPTOR            IdtDescriptor;

  AsmReadIdtr (&IdtDescriptor);
  IdtEntry = (IA32_IDT_GATE_DESCRIPTOR *) IdtDescriptor.Base;

  return (VOID *) (IdtEntry[ExceptionNum].Bits.OffsetLow |
                  (((UINTN)IdtEntry[ExceptionNum].Bits.OffsetHigh) << 16) |
                  (((UINTN)IdtEntry[ExceptionNum].Bits.OffsetUpper) << 32));
} 

/**
  Set exception handler in IDT table by ExceptionNum.

  @param[in]  ExceptionNum      Exception number
  @param[in]  ExceptionHandler  Exception Handler to be set 

**/
VOID
SetExceptionHandlerInIdtEntry (
  IN UINTN             ExceptionNum,
  IN VOID              *ExceptionHandler
  )
{
  IA32_IDT_GATE_DESCRIPTOR   *IdtEntry;
  IA32_DESCRIPTOR            IdtDescriptor;

  AsmReadIdtr (&IdtDescriptor);
  IdtEntry = (IA32_IDT_GATE_DESCRIPTOR *) IdtDescriptor.Base;

  IdtEntry[ExceptionNum].Bits.OffsetLow   = (UINT16)(UINTN)ExceptionHandler;
  IdtEntry[ExceptionNum].Bits.OffsetHigh  = (UINT16)((UINTN)ExceptionHandler >> 16);
  IdtEntry[ExceptionNum].Bits.OffsetUpper = (UINT32)((UINTN)ExceptionHandler >> 32);
}
