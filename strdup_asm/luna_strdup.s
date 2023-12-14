section .text
    global ft_strdup

    extern malloc
    extern ft_strlen
    extern ft_strcpy
    extern __errno_location

ft_strdup:
    ;this function uses rdi (const char *str)

;------------------------------------> unbalance
    push rbp ; prologue / dynamic stack allocation 
    mov rbp, rsp ; set rbp (base pointer) to current stack pointer

            ;---------------------> balance
    
    cmp rdi, 0
    jz _exit

    push rdi ;------------------------------------> unbalance
    sub rsp, 0x8;-----------------------> balance
    call ft_strlen
    mov rdi, rax

    inc rdi ; len++
    call malloc wrt ..plt ; with respect to plt Procedure Linkage Table 
    cmp rax, 0 ; check if malloc failed
    je .error

    add rsp, 0x8;-------------------------------------> unbalance
    pop rdi ;------------------------------> balance

    mov rsi, rdi
    mov rdi, rax
    call ft_strcpy
    mov rax, rdi
    jmp _exit

.error:
    neg rax ; get absolute value of syscall return value
    mov rdi, rax ; mov valeur de rax dans rdi pour errno
    call __errno_location wrt ..plt
    mov [rax], rdi ; modifie la valeur a cette adresse memoire
    mov rax, 0

_exit:
    leave ;-------------------------------------> unbalance
    ret ;---------------------------------->BALANCE
