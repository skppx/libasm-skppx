section .text
    global ft_strcpy

ft_strcpy:

    ;   rdi - destination string address
    ;   rsi - source string address


copy_loop:
    mov al, [rsi]   ; load the byte from source(rsi) into AL register
    mov [rdi], al   ; store the byte at destination (rdi)

    cmp al, 0       ; Check if it's the null terminator
    je end_copy     ; If true exit the loop

    inc rsi         ; move to the next byte in source (rsi)
    inc rdi         ; same but in destination (rdi)

    jmp copy_loop   ; Repeat the loop

end_copy:
    ret

