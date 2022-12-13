.model small
.stack 100h
.data
arrayW word 1000h,2000h,3000h ;set values 
.code
start:
    mov ax,@data
    mov ds,ax
    mov si,offset arrayW
    mov ax,[si]
    add si,2
    mov ax,[si]
    inc si
    inc si
    mov ax,[si]
    end start