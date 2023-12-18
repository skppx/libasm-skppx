section .text
    global ft_strcpy

ft_strcpy:

    ;   rdi - destination string address
    ;   rsi - source string address

   ; xor rax, rax    ; Clear rax to use it as a counter
    mov esi, rsi
    mov edi, rdi

copy_loop:
    mov eax, [esi]   ; load the byte from source(rsi) into AL register
    mov [edi], eax   ; store the byte at destination (rdi)

    cmp eax, 0       ; Check if it's the null terminator
    je end_copy     ; If true exit the loop

    inc esi         ; move to the next byte in source (rsi)
    inc edi         ; same but in destination (rdi)

    jmp copy_loop   ; Repeat the loop

end_copy:
    mov BYTE [edi], 0
    mov rax, edi
    ret

