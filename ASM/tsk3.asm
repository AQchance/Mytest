; 实验三
IO273_0 equ 0230h
IO273_1 equ 0231h
IO244 equ 0230h
mystack segment stack
	dw	  100 dup(?)
mystack  ends

data  segment

data  ends

code  segment
	assume ds:data, ss:mystack, cs:code
delay proc
	push cx
	xor cx, cx
	loop $
	pop cx
	ret
delay  endp


light_left2right proc
	push ax
	push dx
	push cx
	push bx
	mov cx,16 
	mov bx, 0FFFFh
light_left:
	shr bx, 1
	mov dx, IO273_0
	mov al, bh 
	out dx, al
	mov dx, IO273_1
	mov al, bl 
	out dx, al
	call delay
	loop light_left

	pop bx
	pop cx
	pop dx
	pop ax
	ret
light_left2right endp

light_right2left proc
	push ax
	push dx
	push cx
	push bx
	mov cx, 16
	mov dx, IO273_0
	mov bx,0ffffh
light_right:
	shl bx, 1
	mov dx, IO273_0
	mov al, bh 
	out dx, al
	mov dx, IO273_1
	mov al, bl 
	out dx, al
	call delay
	loop light_right 

	pop bx
	pop cx
	pop dx
	pop ax
light_right2left endp

normal_light proc
	push dx
	mov dx, IO273_0
	out dx, al
	mov dx, IO273_1
	out dx, al
	pop dx
	ret
normal_light endp

main proc
	mov dx, IO244
begin:
	in al, dx
	cmp al, 0ffh
	jz ll
	cmp al, 00h
	jz lr
	jmp ln
ll:
	call light_left2right
	jmp begin
lr:
	call light_right2left
	jmp begin
ln:
	call normal_light
	jmp begin
main endp

code  ends
end main