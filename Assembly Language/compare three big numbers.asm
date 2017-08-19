; Problem Statement: Put three numbers 111,222,333 in the three registers AX, BX, CX respectively. Write a program to excute 
; the following:
;               if (AX>CX)
;                    then if (CX>BX)
;                           print "AX contains LARGEST value"
;                    else 
;                           print "CX contains SMALLEST value"
;               else 
;                    then if (CX>BX)
;                           print "CX contains LARGEST value"    
;                    else
;                           print "AX contains the SMALLEST value"



name "Compare-three-numbers" 

org 100h 

.data

axlrg db "AX contains LARGEST value $"
cxsml db "CX contains the SMALLEST value $"
cxlrg db "CX contains the LARGEST value $"
axsml db "AX contains the SMALLEST value $"


.code
mov ax,@data
mov ds,ax  

mov ax,111
mov bx, 222
mov cx,333

cmp ax,cx

jg axborocx
jl axchotocx

axborocx:
        cmp cx,bx
        
        jg cxborobx
        jl cxchotobx
        
        cxborobx: 
                 lea dx,axlrg
                 mov ah,9
                 int 21h
                 jmp endif
        
        cxchotobx:
                 lea dx,cxsml
                 mov ah,9
                 int 21h
                 jmp endif
        
axchotocx:
        cmp cx,bx
        jg cxborothenbx
        jl cxchotothenbx
        
        cxborothenbx:
                lea dx,cxlrg
                mov ah,9
                int 21h
                jmp endif
        cxchotothenbx:
                lea dx,axsml
                mov ah,9
                int 21h
                jmp endif

endif:

ret




