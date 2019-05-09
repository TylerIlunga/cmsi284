	global	main
	extern	puts
	extern  strlen
	extern	reverse_range_in_place  ; Look ma, no .h

	section	.text
main:
	push r12  ; caller-save register
	push r13  ; caller-save register
	mov r12, rsi ; r12 = argv
	mov r13, rdi ; r13 = argc
	call print_reversed_string
check_for_more_arguments:
	dec r13
	jnz print_reversed_string

	pop r13  ; restore caller-save register
	pop r12  ; restore caller-save register
	pop rdi ; restore register after syscalls
	ret
print_reversed_string:
	mov rdi, [r12]
	call strlen
	sub rax, 1 ; subtract one to the args length
	mov rdi, rax

	mov rdi, [r12]
	mov rsi, 0
	mov rdx, rax
	call reverse_range_in_place

	mov rdi, [r12]
	call puts

	add r12, 8 ; points to the next argument
	jmp check_for_more_arguments