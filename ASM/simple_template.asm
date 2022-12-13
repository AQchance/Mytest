.model small
.stack 100h
.data
message db 'Hello, world!',0dh,0ah,'$'
.code
start:
    mov ax,@data
    mov ds,ax
    mov ah,9
    mov dx,offset message
    int 21h
    mov ah,4ch
    int 21h
    end start