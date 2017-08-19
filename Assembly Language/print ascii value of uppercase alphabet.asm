; Problem Statement: Write a program to print the ascii values of the hex digits. 
; if the users type othe letters than A-F or lowercase letters, then print a message & break other wise loop this process.
; (Hint: Use variable to store the input and compare them with the range A-F by using ascii value, use necessary jump commands for this);



name "Print-ascii-value-of-uppercase-alphabet"

org 100h

.data
digit db ?
msg1 db "Enter a hexadecimal digit: $"
msg2 db "In decimal it is: $"
msg3 db "You have mistyped a hexadecimal digit: $"

.code
mov ax,@data
mov ds,ax  

while:

lea dx,msg1
mov ah,9
int 21h

mov ah,1
int 21h
mov digit,al 

mov dl, 0ah
mov ah,2
int 21h
    
mov dl, 0dh
mov ah,2
int 21h 

mov al,digit

cmp al,'A'

jl finished 

cmp al, 'F'

jg finished   

lea dx,msg2
mov ah,9
int 21h 

mov dl,'1'
mov ah,2
int 21h

mov al,digit 

sub al,17
mov dl,al
mov ah,2
int 21h
    

mov dl, 0ah
mov ah,2
int 21h
    
mov dl, 0dh
mov ah,2
int 21h   

jmp while
             

finished:  

    mov dl, 0ah
    mov ah,2
    int 21h
    
    mov dl, 0dh
    mov ah,2
    int 21h
    
    lea dx,msg3
    mov ah,9
    int 21h 
    
    jmp endif

endif:
ret
