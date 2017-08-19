
name "Toggle-Alphabet"

org 100h

.data 
a db ? 
msg db "This is a hexadecimal digit. $"

.code
mov ax, @data
mov ds,ax   


mov ah,1
int 21h
mov a,al

mov dl,0ah
mov ah,2
int 21h

mov dl,0dh
mov ah,2
int 21h

mov al,a

cmp al,'Z'

jg convertToUpper 

cmp al,'a'

jl convertToLower

convertToUpper:
    mov al,a
    sub al,20h 
    mov dl,al
    mov ah,2
    int 21h  
    
    mov a,al
    
    mov dl,0ah 
    mov ah,2
    int 21h

    mov dl,0dh
    mov ah,2
    int 21h
    
    mov al,a
    cmp al,'G'
    
    jl printHexa 
    jmp endif   
    
    printHexa:
            lea dx,msg
            mov ah,9
            int 21h
    jmp endif  

convertToLower:
    
    add al,20h  
    mov dl,al
    mov ah,2
    int 21h
    
    jmp endif


endif:
ret
