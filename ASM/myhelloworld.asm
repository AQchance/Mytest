stack segment stack
    db 100 dup (0)
stack ends
data  segment
    message db 'Hello, world!',0dh,0ah,'$'
data ends
code segment
    assume cs:code,ds:data,ss:stack
start:
    mov ax,data
    mov ds,ax
    mov ah,9
    mov dx,offset message
    int 21h
    mov ah,4ch
    int 21h
code ends  
    end start