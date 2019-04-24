        global main
        extern printf
        
        section .text
main:
        cmp rdi, 2
        jne error0

        mov rdi, [rsi + 8]
        mov rax, 87
        xor rbx, rbx
        syscall

        mov rdi, format_info,
        xor rax, rax
        call printf
        ret
error0:
        mov rdi, error_output0
        xor rax, rax
        call printf
        ret
error_output0:
        db "This program requires only one command line argument.", 53, 0
format_info:
        db "Go check, the file specified was deleted.", 0
    