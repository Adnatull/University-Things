; Problem Statement: Take a letter as a random input (it could be uppercase or lowercase) from user. Whatever the input is, toggle
; the case; means, if it is an uppercase letter than convert it to lower case letter, or if it is a lowercase letter than convert it into
; uppercase. Check output and print a message if it is a hexadecimal digit in the range A-F. (Hint: Compare the user input with 'Z' and
; toggle it by adding or subtracting necessary values; then compare it with range of A-F and print a message as shown below)
;
; Sample input: x
; Sample Output: X
; 
; Sample input: a
; Sample output: A
;                This is a hexadecimal digit.

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
