section .text
    global ft_strcmp

ft_strcmp:

    ;   rdi - s1 string address
    ;   rsi - s2 string address

compare_loop:
    mov     al, byte [rdi]       ; load the byte from s1(rdi) into AL register
    cmp     al, byte [rsi]       ; compare the byte between s1 and s2 (al and rsi)
    je      continue_loop   ; jump if equal

    sub     al, byte [rsi]       ; s1 - s2
    js      negative_result
    ret

continue_loop:
    test    al, al          ; check if end of string
    je      done            ;if true return 0;

    inc     rdi             ;move to the next byte in s1
    inc     rsi             ;move to the next byte in s2
    jmp     compare_loop    ;continue the loop

negative_result:
    neg al
    neg eax
    ret

done:
    ret
