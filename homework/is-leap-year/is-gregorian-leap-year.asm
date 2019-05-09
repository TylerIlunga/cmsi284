        global main
        extern atoi
        extern printf
        extern puts

        section .text
main:   
        cmp rdi, 2
        jne handle_arg_count_error

        push r12
        mov r12, [rsi + 8]
        mov rdi, r12
        call atoi
        cmp eax, 0
        je handle_invalid_arg_error
        mov esi, eax
        
        mov edx, 0
        mov eax, esi
        mov ebx, 4
        div ebx
        cmp edx, 0
        jne is_not_a_leap_year

        mov edx, 0
        mov eax, esi
        mov ebx, 100
        div ebx
        cmp edx, 0
        jne is_a_leap_year

        mov edx, 0
        mov eax, esi
        mov ebx, 400
        div ebx
        cmp edx, 0
        jne is_not_a_leap_year

        jmp is_a_leap_year
is_a_leap_year:
        mov rdi, is_a_leap_year_format
        mov rsi, r12
        call printf
        jmp done
is_not_a_leap_year:
        mov rdi, is_not_a_leap_year_format
        mov rsi, r12
        call printf
        jmp done
done:
        pop r12
        ret
handle_arg_count_error:
        mov rdi, arg_count_error_output
        call puts
        ret
handle_invalid_arg_error: 
        mov rdi, invalid_arg_output
        call puts
        jmp done
arg_count_error_output:
        db "This program requires exactly one command line argument specifying a year.", 0
invalid_arg_output:
        db "0 is a leap year.", 0
is_a_leap_year_format:
        db "%s is a leap year.", 13, 10, 0
is_not_a_leap_year_format:
        db "%s is not a leap year.", 13, 10, 0