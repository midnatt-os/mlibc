.extern __mlibc_entry

.section .text
.global _start
_start:
	move $a0, $sp
	la $a1, main
	b __mlibc_entry
	break 0

.section .note.GNU-stack,"",%progbits
