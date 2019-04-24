        global main
        extern printf
        extern atoi
        
        section .text
main:
        cmp rdi, 2
        jne error0

        mov r12, [rsi + 8]
        mov rdi, r12
        call atoi
        cmp eax, 0
        jne error1

        mov rdi, r12
        mov rax, 87
        xor rbx, rbx
        syscall
        cmp eax, 0
        jne error2

        mov rdi, format_info
        jmp done
error0:
        mov rdi, error_output0
        jmp done
error1:
        mov rdi, error_output1
        jmp done
error2: 
        mov rdi, error_output2
        jmp done
done:
        xor rax, rax
        call printf
        ret
error_output0:
        db "This program requires only one command line argument.", 53, 0
error_output1:
        db "You must enter a string containing the pathname.", 0
error_output2:
        db "That path does not exist.", 0
format_info:
        db "Go check, the file specified was deleted.", 0
    