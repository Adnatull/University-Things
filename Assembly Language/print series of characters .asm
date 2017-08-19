; Problem Description: You are given a character. The character will be 'a' or 'A' or 0. Your job is to identify the character &
; if the character is 0 then print up to 9 from 0, else if the character is 'a' then print up to 'z' from 'a', else print up to 'Z' from 'A'.

; Sample Input:
; 0
;
;Sample output:
; 0
; 1
; 2
; 3
; 4
; 5
; 6
; 7
; 8
; 9 


name "print-character"

org 100h

.data

sym db ?
msg1 db "Enter the character: $"

.code
mov ax,@data
mov dx,ax

lea dx, msg1
mov ah,9
int 21h

mov ah,1
int 21h
mov sym,al

mov dl,0Ah
mov ah,2
int 21h

mov dl,0Dh
mov ah,2
int 21h

 

mov bl,0
mov al,sym 

cmp al,30h

jg ascii 
je number

mov dx,0h


ascii:
    
   while: cmp bl,26
        je endif
        
        mov cl,al
        
        mov dl,al
        mov ah,2
        int 21h   
        

        mov dl,0Ah
        mov ah,2
        int 21h


        mov dl,0Dh
        mov ah,2
        int 21h  
        
        mov al,cl
        
        add al,1h
        inc bl 
        
        jmp while 
        
number:

    while_: cmp bl,10
            je endif  
            
            mov cl,al
            
            mov dl,al
            mov ah,2
            int 21h 
            
            mov dl,0Ah
            mov ah,2
            int 21h


            mov dl,0Dh
            mov ah,2
            int 21h  
            
            mov al,cl
        
            
            add al,1h
            inc bl
            
            jmp while_
    
        
        
endif: 

ret
