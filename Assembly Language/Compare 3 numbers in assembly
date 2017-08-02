name "add-sub"

org 100h

.data


;declaring data segment
num1 db ?
num2 db ?
num3 db ?
msg1 db "Enter the first number: $"
msg2 db "Enter the second number: $"
msg3 db "Enter the third number: $"
smaller db ,"Smaller number is: $"
middle db "Middle number is: $"
bigger db "Bigger number is: $"

.code
;moving data segment to ax register
mov ax,@data
mov ds,ax

;asking user to give input first number
lea dx,msg1
mov ah,9
int 21h

;taking input of first number
mov ah,1
int 21h
sub al,30h
mov num1,al 

;going to next line
mov dl,0Ah
mov ah,2
int 21h

;shifting the cursor location to leftmost place
mov dl,0Dh
mov ah,2
int 21h

;asking user to give input second number
lea dx,msg2
mov ah,9
int 21h

;taking input of second number
mov ah,1
int 21h
sub al,30h
mov num2,al  

;going to next line
mov dl,0Ah
mov ah,2
int 21h

;shifting the cursor to leftmost place
mov dl,0Dh
mov ah,2
int 21h

;asking user to give input third number
lea dx,msg3
mov ah,9
int 21h

;taking input of third number
mov ah,1
int 21h
sub al,30h
mov num3,al  

;going to next line
mov dl,0Ah
mov ah,2
int 21h

;shifting the cursor to leftmost position
mov dl,0Dh
mov ah,2
int 21h

   
;moving first number to al 
mov al, num1

;moving second number to bl
mov bl, num2               

;moving third number to cl
mov cl, num3    

;comparing first number & second number
cmp al,bl


jg aGreaterb ;if first number greater than second number
jl aLessb    ;if first number less than second number



aGreaterb: ; first number greater than second number 
    
    ;comparing second number with third number
    cmp bl,cl                                 
    
    jg bGreaterC ;if second number greater than third number
    jl bLessC  ;if second number less than third number
    
    bGreaterC:   ; 2nd number greater than 3rd number
    
        ;printing message of smaller number        
        lea dx,smaller
        mov ah,9
        int 21h 
        
        ;printing smaller number
        add num3, 30h
        mov dl,num3
        mov ah,2
        int 21h 
        
        ;going to next line        
        mov dl,0Ah
        mov ah,2
        int 21h

        mov dl,0Dh
        mov ah,2
        int 21h

        ;printing message of middler number
        lea dx, middle
        mov ah,9
        int 21h
        
        ;printing middle number
        add num2,30h
        mov dl,num2
        mov ah,2
        int 21h 
        
        ;goint to next line
        mov dl,0Ah
        mov ah,2
        int 21h

        mov dl,0Dh
        mov ah,2
        int 21h

        ;printing message of bigger number
        lea dx, bigger
        mov ah,9
        int 21h
        
        ;printing bigger number
        add num1,30h
        mov dl,num1
        mov ah,2
        int 21h
        
        jmp endif 
        
    bLessC: ; 2nd number is less than 3rd number
        
        
        
        cmp al,cl  ; comparing 1st number with 3rd number
        jg aGreater_c ; if 1st number is greater than 3rd number
        jl aLess_c    ; if 1st number is less than 3rd number
        
        aGreater_c:  ;1st number is greater than 3rd number
             
             ;line 180 to 187 is for smaller number 
             lea dx,smaller
             mov ah,9
             int 21h 
     
             add num2, 30h
             mov dl,num2
             mov ah,2
             int 21h 
             
             mov dl,0Ah
             mov ah,2
             int 21h

             mov dl,0Dh
             mov ah,2
             int 21h

             ;line 198 to 205 is for middle number
             lea dx, middle
             mov ah,9
             int 21h
            
             add num3,30h
             mov dl,num3
             mov ah,2
             int 21h 
             
             mov dl,0Ah
             mov ah,2
             int 21h

             mov dl,0Dh
             mov ah,2
             int 21h

             ;line 216 to 223 is for bigger number 
             lea dx, bigger
             mov ah,9
             int 21h
             
             add num1,30h
             mov dl,num1
             mov ah,2
             int 21h 
             
             mov dl,0Ah
             mov ah,2
             int 21h

             mov dl,0Dh
             mov ah,2
             int 21h

             
             jmp endif
             
        aLess_c:  
        
             lea dx,smaller
             mov ah,9
             int 21h 
     
             add num2, 30h
             mov dl,num2
             mov ah,2
             int 21h 
             
             mov dl,0Ah
             mov ah,2
             int 21h

             mov dl,0Dh
             mov ah,2
             int 21h
            
             lea dx, middle
             mov ah,9
             int 21h
            
             add num1,30h
             mov dl,num1
             mov ah,2
             int 21h
             
             mov dl,0Ah
             mov ah,2
             int 21h

             mov dl,0Dh
             mov ah,2
             int 21h
             
             lea dx, bigger
             mov ah,9
             int 21h 
             
             add num3,30h
             mov dl,num3
             mov ah,2
             int 21h
             
             mov dl,0Ah
             mov ah,2
             int 21h

             mov dl,0Dh
             mov ah,2
             int 21h
             
             jmp endif

aLessb: 
    cmp al,cl
    jg aGreaterc
    jl aLessc
    
    aGreaterc: 
    
        lea dx,smaller
        mov ah,9
        int 21h 
    
        add num3,30h
        mov dl,num3
        mov ah,2
        int 21h 
        
        mov dl,0Ah
        mov ah,2
        int 21h

        mov dl,0Dh
        mov ah,2
        int 21h
        
        lea dx, middle
        mov ah,9
        int 21h 
        
        add num1,30h
        mov dl,num1
        mov ah,2
        int 21h
        
        mov dl,0Ah
        mov ah,2
        int 21h

        mov dl,0Dh
        mov ah,2
        int 21h
        
        lea dx, bigger
        mov ah,9
        int 21h
        
        add num2,30h
        mov dl,num2
        mov ah,2
        int 21h
        
        mov dl,0Ah
        mov ah,2
        int 21h

        mov dl,0Dh
        mov ah,2
        int 21h
        
        jmp endif  
        
    aLessc:  
    
        cmp bl,cl
        
        jg bGreater_c
        jl bLess_c 
        
        bGreater_c: 
        
        lea dx, smaller
        mov ah,9
        int 21h
        
        add num1,30h
        mov dl,num1
        mov ah,2
        int 21h
        
        mov dl,0Ah
        mov ah,2
        int 21h

        mov dl,0Dh
        mov ah,2
        int 21h
        
        lea dx, middle
        mov ah,9
        int 21h
        
        add num3,30h
        mov dl, num3
        mov ah,2
        int 21h
        
        mov dl,0Ah
        mov ah,2
        int 21h

        mov dl,0Dh
        mov ah,2
        int 21h
        
        lea dx, bigger
        mov ah,9
        int 21h
        
        add num2,30h
        mov dl, num2
        mov ah,2
        int 21h
        
        jmp endif
        
        bLess_c:
        
        lea dx, smaller
        mov ah,9
        int 21h
        
        add num1,30h
        mov dl,num1
        mov ah,2
        int 21h
        
        mov dl,0Ah
        mov ah,2
        int 21h
        
        mov dl, 0Dh
        mov ah,2
        int 21h
        
        lea dx,middle
        mov ah,9
        int 21h
        
        add num2,30h
        mov dl,num2
        mov ah,2
        int 21h
        
        mov dl,0Ah
        mov ah,2
        int 21h
        
        mov dl,0Dh
        mov ah,2
        int 21h  
        
        lea dx, bigger
        mov ah,9
        int 21h
        
        add num3,30h
        mov dl, num3
        mov ah,2
        int 21h
        
        
        
        jmp endif
          

    

endif:

ret


