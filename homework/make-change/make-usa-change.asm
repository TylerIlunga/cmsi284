        global main
        extern atoi
        extern printf
        extern puts

        section .text
main:   
        cmp rdi, 2
        jne handle_arg_count_error

        push rbx
        mov rbx, [rsi + 8]
        mov rdi, rbx
        call atoi
        cmp eax, 0
        je handle_invalid_arg_error

        xor r12, r12  ; total quarters
        xor r13, r13 ; total dimes
        xor r14, r14 ; total nickels
        xor r15, r15 ; total pennies

        mov rdi, rbx
        call atoi
        mov ebx, eax

        jmp make_change
make_change:
        cmp ebx, 0
        je print_change

        cmp ebx, 25
        jge gather_quarter
        cmp ebx, 10
        jge gather_dime
        cmp ebx, 5
        jge gather_nickel
        cmp ebx, 1
        jge  gather_penny
gather_quarter:
        inc r12
        sub ebx, 25
        jmp make_change
gather_dime:
        inc r13
        sub ebx, 10
        jmp make_change
gather_nickel:
        inc r14
        sub ebx, 5
        jmp make_change
gather_penny:
        inc r15
        sub ebx, 1
        jmp make_change
print_change:
        mov rdi, change_format
        mov rsi, r12
        mov rdx, r13
        mov rcx, r14
        mov r8, r15
        call printf
        jmp done0
done0:
        pop rbx
        ret
handle_arg_count_error:
        mov rdi, arg_count_error_output
        call puts
        ret
handle_invalid_arg_error:
        mov rdi, change_format
        xor rsi, rsi
        xor rdx, rdx
        xor rcx, rcx
        xor r8, r8
        call printf
        jmp done0
arg_count_error_output:
    db "This program requires exactly one integer command line argument.", 0
change_format:
    db "Quarters: %d", 13, 10, "Dimes: %d", 13, 10, "Nickels: %d", 13, 10, "Pennies: %d", 13, 10, 0
