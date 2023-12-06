global ft_strlen

ft_strlen:
    ; Input: rdi = pointer to the null-terminated string
    ; Output: rax = length of the string
    
    xor rax, rax          ; Initialize the length to zero

    repeat_loop:
        cmp byte [rdi], 0  ; Check if the current character is null
        je done                ; If null, we are done
        inc rax                ; Increment the length
        inc rdi                ; Move to the next character
        jmp repeat_loop        ; Repeat the loop

    done:
        ret

