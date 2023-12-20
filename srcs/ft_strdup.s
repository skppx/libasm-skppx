global ft_strdup
extern ft_strcpy
extern ft_strlen
extern malloc
    ; char *strdup(const char *s)

ft_strdup:

    push    rbp
    mov     rbp, rsp     ; stack balance
    push    rdi
    call    ft_strlen    ; length of s in rax
    inc     rax          ; +1 to the length for '\0'
    mov     rdi, rax     ; set the size parameter for malloc
    call    malloc wrt ..plt      ; call malloc rdi as parameter rax as return value
    pop     rsi          ; save source string in the stack
    
    test    rax, rax        ; check if NULL (malloc check)
    je      malloc_failed

    mov     rdi, rax    ; set the new malloced string as parameter for strcpy
    call ft_strcpy      ; call ft_strcpy
    mov     rax, rdi    ; put the copied string in rax for return
    leave
    ret                 ; return the new allocated string

malloc_failed:

    mov     rax, 0      ; set rax to 0
    ret                 ; return 0
