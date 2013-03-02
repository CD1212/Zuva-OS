/*
 * isr.c - The x86 IDT implementation
 *
 *
 * This file is part of the Zuva Operating System.
 *
 * (C) 2013 Chris Dyer
 *
 */

#include <arch/x86.h>
#include <utils.h>
#include <types.h>
#include <irq.h>

extern void _isr0();
extern void _isr1();
extern void _isr2();
extern void _isr3();
extern void _isr4();
extern void _isr5();
extern void _isr6();
extern void _isr7();
extern void _isr8();
extern void _isr9();
extern void _isr10();
extern void _isr11();
extern void _isr12();
extern void _isr13();
extern void _isr14();
extern void _isr15();
extern void _isr16();
extern void _isr17();
extern void _isr18();
extern void _isr19();
extern void _isr20();
extern void _isr21();
extern void _isr22();
extern void _isr23();
extern void _isr24();
extern void _isr25();
extern void _isr26();
extern void _isr27();
extern void _isr28();
extern void _isr29();
extern void _isr30();
extern void _isr31();
extern void _isr127();

irq_handler_t isrs_routines[256];

void isr_install_handler(int isrs, irq_handler_t handler)
{
  isrs_routines[isrs] = handler;
}

void arch_isr_install()
{
  arch_idt_set_gate(0,  (uint32_t)_isr0, 0x08, 0x8E);
  arch_idt_set_gate(1,  (uint32_t)_isr1, 0x08, 0x8E);
  arch_idt_set_gate(2,  (uint32_t)_isr2, 0x08, 0x8E);
  arch_idt_set_gate(3,  (uint32_t)_isr3, 0x08, 0x8E);
  arch_idt_set_gate(4,  (uint32_t)_isr4, 0x08, 0x8E);
  arch_idt_set_gate(5,  (uint32_t)_isr5, 0x08, 0x8E);
  arch_idt_set_gate(6,  (uint32_t)_isr6, 0x08, 0x8E);
  arch_idt_set_gate(7,  (uint32_t)_isr7, 0x08, 0x8E);
  arch_idt_set_gate(8,  (uint32_t)_isr8, 0x08, 0x8E);
  arch_idt_set_gate(9,  (uint32_t)_isr9, 0x08, 0x8E);
  arch_idt_set_gate(10, (uint32_t)_isr10, 0x08, 0x8E);
  arch_idt_set_gate(11, (uint32_t)_isr11, 0x08, 0x8E);
  arch_idt_set_gate(12, (uint32_t)_isr12, 0x08, 0x8E);
  arch_idt_set_gate(13, (uint32_t)_isr13, 0x08, 0x8E);
  arch_idt_set_gate(14, (uint32_t)_isr14, 0x08, 0x8E);
  arch_idt_set_gate(15, (uint32_t)_isr15, 0x08, 0x8E);
  arch_idt_set_gate(16, (uint32_t)_isr16, 0x08, 0x8E);
  arch_idt_set_gate(17, (uint32_t)_isr17, 0x08, 0x8E);
  arch_idt_set_gate(18, (uint32_t)_isr18, 0x08, 0x8E);
  arch_idt_set_gate(19, (uint32_t)_isr19, 0x08, 0x8E);
  arch_idt_set_gate(20, (uint32_t)_isr20, 0x08, 0x8E);
  arch_idt_set_gate(21, (uint32_t)_isr21, 0x08, 0x8E);
  arch_idt_set_gate(22, (uint32_t)_isr22, 0x08, 0x8E);
  arch_idt_set_gate(23, (uint32_t)_isr23, 0x08, 0x8E);
  arch_idt_set_gate(24, (uint32_t)_isr24, 0x08, 0x8E);
  arch_idt_set_gate(25, (uint32_t)_isr25, 0x08, 0x8E);
  arch_idt_set_gate(26, (uint32_t)_isr26, 0x08, 0x8E);
  arch_idt_set_gate(27, (uint32_t)_isr27, 0x08, 0x8E);
  arch_idt_set_gate(28, (uint32_t)_isr28, 0x08, 0x8E);
  arch_idt_set_gate(29, (uint32_t)_isr29, 0x08, 0x8E);
  arch_idt_set_gate(30, (uint32_t)_isr30, 0x08, 0x8E);
  arch_idt_set_gate(31, (uint32_t)_isr31, 0x08, 0x8E);

  //idt_set_gate(SYSCALL_VECTOR, (unsigned)_isr127, 0x08, 0x8E);

  kprintf("[x86] ISRs initialized\n");
}

void arch_isr_handler(struct registers *regs)
{
  kprintf("Received interrupt %d\n", regs->int_no);
}

