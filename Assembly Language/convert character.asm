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