section .text
    global ft_strcmp

ft_strcmp:

    ;   rdi - s1 string address
    ;   rsi - s2 string address

compare_loop:
    movzx   eax, byte [rdi]     ; load the byte from s1(rdi) into eax register and sign it
    cmp     al, byte [rsi]      ; compare the byte between s1 and s2 (al(byte of eax) and rsi)
    je      continue_loop       ; jump if equal

    sub     al, byte [rsi]      ; s1 - s2
    jnc     done                ; jump if no carry
    jb      negative_result     ; jump if below (negative result)
    ret

continue_loop:
    test    al, al          ; check if end of string (al == 0)
    je      done            ; if true return 0;

    inc     rdi             ;move to the next byte in s1
    inc     rsi             ;move to the next byte in s2
    jmp     compare_loop    ;continue the loop

negative_result:
    neg al                  ; negate al to cancel overflow
    neg eax                 ; negate the whole int because of strcmp return type

done:
    ret
