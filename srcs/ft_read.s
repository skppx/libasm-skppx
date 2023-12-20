extern  __errno_location

section .text
    global ft_read

ft_read:
    mov rax, 0  ; syscall for read
    syscall
    cmp rax, 0  ; check return value for error
    jl  error
    ret

error:
    neg rax
    push rax    ; store error return value
    call __errno_location wrt ..plt ; call errno
    pop  qword [rax]                ; set errno number
    mov  rax, -1    ; return -1 for error
    ret
