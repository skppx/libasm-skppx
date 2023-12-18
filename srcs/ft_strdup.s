global ft_strdup
extern ft_strcpy
extern ft_strlen
extern malloc
    ; char *strdup(const char *s)

ft_strdup:

    push    rbp
    mov     rbp, rsp     ; alligne
    push    rdi
    call    ft_strlen   ; length of s in rax
    inc     rax        ; +1 to the length for '\0'
    mov     rdi, rax    ; set the size parameter for malloc
   ; sub     rsp, 0x8
    call    malloc wrt ..plt      ; call malloc rdi as parameter rax as return value
   ; add     rsp, 0x8
    pop     rsi
    
   ;  malloc check
    test    rax, rax    ; check if NULL
    je      malloc_failed

    mov     rdi, rax    ; set the dest parameter for strcpy
   ; sub     rsp, 0x8
    call ft_strcpy      ; call ft_strcpy
   ; add     rsp, 0x8
    mov     rax, rdi
    leave
    ret                 ; return the new allocated string

malloc_failed:

    mov     rax, 0      ; set rax to 0
    ret                 ; return 0
