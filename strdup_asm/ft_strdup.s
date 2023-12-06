global ft_strdup
extern ft_strcpy
extern ft_strlen
extern malloc
    ; char *strdup(const char *s)

ft_strdup:

    push    rdi         ; save the address of the original string to the stack
    call    ft_strlen   ; length of s in rax
    add     rax, 1      ; +1 to the length for '\0'
    mov     rdi, rax    ; set the size parameter for malloc
    call    malloc      ; call malloc rdi as parameter rax as return value

    ; malloc check
    test    rax, rax    ; check if NULL
    je      malloc_failed

    mov     rdi, rax    ; set the dest parameter for strcpy
    pop     rsi         ; pop the original string address into rsi (parameter src for strcpy)
    call ft_strcpy      ; call ft_strcpy
    ret                 ; return the new allocated string

malloc_failed:

    mov     rax, 0      ; set rax to 0
    ret                 ; return 0
