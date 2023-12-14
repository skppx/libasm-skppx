global ft_strdup
extern ft_strcpy
extern ft_strlen
extern malloc


    ft_strdup:
            push        rbp                   ; prologue                      
            mov         rbp, rsp              ; prologue           
            sub         rsp, 8                ; reserve space for string                   
            mov         qword [rbp - 8], rdi  ; put first param on the stack
            call        ft_strlen           ; strlen the first param
            mov         rdi, rax              ; put return value on the rdi register                       
            call        malloc wrt ..plt                ; malloc rdi bytes                        
            cmp         rax, 0                ; check if malloc failed                                
            je          return                               
            mov         rdi, rax              ; put malloc address in rdi  (DEST)                            
            mov         rsi, qword [rbp - 8]  ; put source address in rsi (SRC)
            call        ft_strcpy            ; copy                 
            add         rsp, 8                ; reset                     
            pop         rbp                   ; epilogue                             
            ret
    
    return:
            xor         rax, rax
            add         rsp, 8                   
            pop         rbp                                     
            ret
