mystack segment stack
	dw 100 dup(?)
mystack  ends

data  segment
	my_data db 'hello world'
	my_data_length dw $ - offset my_data
	id db 'id: 20009201256', '$'
	my_name db 'name: xie kai hua', '$'
	asc db 'ascii is ', '$'
	line_feed db 0dh, 0ah, '$'
	lint_msg1 db 'please input a letter(q or Q with quit): ', '$'
	lint_msg2 db 'the ascii code of string "hello world" is:', 0dh, 0ah, '$'
data  ends

code  segment
	assume ds:data, cs:code, ss:mystack
main PROC
	mov ax, data
	mov ds, ax

; 将字符串my_data转换成对应的ASCII码
	mov cx, my_data_length
	xor si, si
	mov dx, offset lint_msg2
	call put_str
string2ascii:
	mov al, byte ptr my_data[si]
	call put_al
	mov dl, ' '
	mov ah, 02h
	int 21h
	inc si
	loop string2ascii
	mov dx, offset line_feed
	call put_str

; 显示姓名和学号
	mov dx, offset id
	call put_str
	mov dx, offset line_feed
	call put_str
	mov dx, offset my_name
	call put_str
	mov dx, offset line_feed
	call put_str

; 将输入的字符转换成对应的ASCII码
tran2ascii:
	mov dx, offset lint_msg1
	call put_str
	mov ah, 01h
	int 21h
	cmp al, 'q'
	je end_main
	cmp al, 'Q'
	je end_main
	mov dx, offset line_feed
	call put_str
	mov dx, offset asc
	call put_str
	call put_al
	mov dx, offset line_feed
	call put_str
	jmp tran2ascii
end_main:
	mov ah, 4ch
	int 21h
main ENDP

; 输出首地址为ds:dx的字符串, 结尾为'$'
put_str PROC
	push ax
	push dx
	mov  ah, 09h
	int  21h
	pop  dx
	pop  ax
	ret
put_str ENDP

; 输出al寄存器的值, 结果为16进制
put_al PROC
	push ax
	push bx
	push cx
	push dx
	mov bh, al

	;输出高4位
	mov bl, bh
	mov cl, 4
	shr bl, cl
	and bl, 0fh
	add bl, '0'
	cmp bl, '9'
	jbe high_digit
	add bl, 'a'-'0'-10
high_digit:
	mov ah, 02h
	mov dl, bl
	int 21h

	;输出低4位
	mov bl, bh
	mov cl, 4
	and bl, 0fh
	add bl, '0'
	cmp bl, '9'
	jbe low_digit
	add bl, 'a'-'0'-10
low_digit:
	mov ah, 02h
	mov dl, bl
	int 21h

	mov dl, 'H'
	mov ah, 02h
	int 21h

	pop dx
	pop cx
	pop bx
	pop ax
	ret
put_al ENDP

code ends
end main