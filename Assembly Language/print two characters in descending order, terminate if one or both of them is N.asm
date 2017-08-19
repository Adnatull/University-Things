name "Print-two-characters-in-descending-order,-terminate-if-one-or-both-of-them-is-N"

org 100h 

.data

char1 db ?
char2 db ?
msg1 db "In descending order it is: $"
msg2 db "You typed N."
space db " $"

.code

mov ax,@data
mov ds,ax 

while:

mov ah,1
int 21h
mov char1,al  


lea dx,space
mov ah,9
int 21h

mov ah,1
int 21h
mov char2,al   

mov dl,0ah
mov ah,2
int 21h  

mov dl,0dh
mov ah,2
int 21h

mov al, char1
mov bl, char2

cmp al,"N"

je finished

cmp bl, "N"

je finished 

lea dx,msg1
mov ah,9
int 21h    


cmp al,bl

jg char1boro
jl char2boro

char1boro:
        mov dl,char1
        mov ah,2
        int 21h
        
        lea dx,space
        mov ah,9
        int 21h
        
        mov dl, char2 
        mov ah,2
        int 21h 
        
        mov dl,0ah
        mov ah,2
        int 21h  

        mov dl,0dh
        mov ah,2
        int 21h

        jmp while

char2boro:
        mov dl,char2
        mov ah,2
        int 21h
        
        lea dx,space
        mov ah,9
        int 21h
        
        mov dl,char1
        mov ah,2
        int 21h 
        
        mov dl,0ah
        mov ah,2
        int 21h  

        mov dl,0dh
        mov ah,2
        int 21h
        
        jmp while
        


finished: 
        lea dx,msg2
        mov ah,9
        int 21h
        jmp endif 


 

endif:

ret
