section .text
    global ft_strcpy

ft_strcpy:

    ;   rdi - destination string address
    ;   rsi - source string address
    push rbp
    mov rbp, rsp        ; stack balance

    mov rcx, 0          ; set rcx to 0 to use it as a counter

copy_loop:
    mov al, byte rsi[rcx]   ; load the byte from source(rsi) into AL register
    mov byte rdi[rcx], al   ; store the byte at destination (rdi)

    cmp byte rsi[rcx], 0    ; Check if it's the null terminator
    je end_copy             ; If true exit the loop

    inc rcx                 ; rcx++

    jmp copy_loop           ; Repeat the loop

end_copy:
    mov rax, rdi            ; put destination string in rax for return
    leave                   ; stack balance
    ret

