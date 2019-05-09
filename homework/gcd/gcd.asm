        global  gcd       ; uint64_t gcd(uint64_t x, uint64_t y)

        section .text
gcd:
        push r12
        push r13
        mov r12, rdi
        mov r13, rsi

        cmp r12, r13
        je done
        jmp l1
l1:
        cmp r13, 0 ; Base case: y == 0
        je done
        mov rdx, 0
        mov rax, r12 ; rax = dividend(x)
        mov rbx, r13 ; rbx = divisor(y)
        div rbx
        mov r12, r13 ; x = y
        mov r13, rdx; y = x % y
        jmp l1
done: 
        mov rax, r12
        pop r13
        pop r12
        ret
empty_str:
        db "", 0
int_to_str_format: 
        db "%s%d", 0