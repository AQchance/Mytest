mystack segment stack
	dw	  100 dup(?)
mystack  ends

data  segment
	digital_string db 5 dup(?), 0dh, 0ah, '$'
	binary_string db 17 dup(?), 0dh, 0ah, '$'
	; hex_string db 5 dup(?), 0dh, 0ah, '$'
	number dw 0
	highest_digit dw 0
	err_msg db "Error: Please input a digit!",0dh,0ah,'$'
	string_buffer db 128, 128 dup(?),0dh,0ah, '$'
	line_feed db 0dh,0ah,'$'
	lint_msg db  'exit',0dh,0ah, '$'
	lint_msg2 db 'The Dec code of the number is ', '$'
	lint_msg3 db 'Please input a digit(q or Q for quit): ', '$'
	lint_msg4 db 'Please input a string: ',0dh,0ah, '$'
	lint_msg5 db 'The number of digits in the string is ', '$'
	lint_msg6 db 'The hex code is ', '$'
data  ends

code  segment
	assume ds:data, ss:mystack, cs:code
; 当cf为1时，并且存储最高位的high_digit没有没置数过，就将high_digit置为1
check_cf proc
	jnc cf_0
	cmp highest_digit, 0
	jne cf_0
	mov highest_digit, 1
cf_0:
	ret
check_cf endp

num2bin proc ;将dw(number)转换为二进制串
	push dx
	push ax
	push cx
	push si


	mov si, offset binary_string
	mov byte ptr [si], '0'
	cmp highest_digit, 0
	je clear_highest_digit
	mov byte ptr [si], '1'
clear_highest_digit:
	; mov highest_digit, 0

	mov si, offset binary_string + 17
	mov ax, number

	mov cx, 16
mod2:
	dec si
	shr ax, 1
	jc odd_
even_:
	mov byte ptr [si], '0'
	jmp end_mod2
odd_:
	mov byte ptr [si], '1'
	jmp end_mod2
	
end_mod2:
	loop mod2

	pop si
	pop cx
	pop ax
	pop dx
	ret
num2bin endp

num2hex_and_disp proc
	push ax
	push bx
	push dx

	mov bx, number
	mov dl, '0'
	cmp highest_digit, 0
	je zero_highest_digit
	mov dl, '1'
zero_highest_digit:
	mov ah, 02h
	int 21h

	mov al, bh
	call toasc
	mov al, bl
	call toasc

	mov dx, offset line_feed
	call dispstr

	pop dx
	pop bx
	pop ax
	ret
num2hex_and_disp endp

; 将十进制串转换成dw, 存到number里
digit2num proc
	push si
	push ax
	push dx
	push bx
	mov si, offset digital_string
	xor ax, ax
	mov bx, 10
	xor dx, dx
digit2num_proc:
	mov dl, [si]
	cmp dl, '$'
	je end_digit2num
	mul bx
	call check_cf
	mov dl, [si]
	sub dx, '0'
	add ax, dx
	call check_cf
	inc si
	jmp digit2num_proc

end_digit2num:
	mov number, ax
	pop bx
	pop dx
	pop ax
	pop si
	ret
digit2num endp


dispstr proc ; 显示起始地址为ds:dx的字符串
	push ax
	mov ah,9
	int 21h
	pop ax
	ret
dispstr endp

;读取长度不超过5的10进制数字符串, 超过的部分会被截断, 如果输入q或Q, 立即退出该子程序, 并将al置为1
;结尾是$, 或者输入第五个数字
read_digital_string proc
	push si
	push ds
	push dx
	push cx
	mov highest_digit, 0
re_read:
	mov si, offset digital_string
	mov cx, 5
	mov ah, 01h
read_digit:
	int 21h
read_check:
	cmp al, 0dh
	je end_read_cr
	cmp al, '$'
	je end_read_cr
	cmp al, 'q'
	je read_q
	cmp al, "Q"
	je read_q
	cmp al, '0'
	jb read_non_digit
	cmp al, '9'
	ja read_non_digit

	mov byte ptr [si], al
	inc si
	loop read_digit
end_read_cr:
	xor ax, ax
	
end_read:
	mov byte ptr [si], '$'

	push ax
	mov dx, offset line_feed
	call dispstr
	pop ax

	pop cx
	pop dx
	pop ds
	pop si
	ret
read_q:
	mov dx, offset line_feed
	call dispstr
	mov dx, offset lint_msg
	call dispstr
	mov al,1
	jmp end_read
read_non_digit:
	mov dx, offset line_feed
	call dispstr
	mov dx, offset err_msg
	call dispstr
	jmp re_read

read_digital_string endp

; 输入一个字符串，计算其中有多少个数字
count_digits proc
	push ax
	push dx
	push bx
	push cx
	push si
	
	mov ah, 0ah
	mov dx, offset string_buffer
	int 21h

	mov si, dx
	inc si
	xor cx, cx
	mov cl, byte ptr [si]
	xor ax, ax
	inc si
	cmp cl, 0
	je output_ax
check_digit:
	mov dl, byte ptr [si]
	cmp dl, '0'
	jb not_digit
	cmp dl, '9'
	ja not_digit
	inc ax
not_digit:
	inc si
	loop check_digit

	mov dx, offset line_feed
	call dispstr

output_ax:
	mov dx, offset lint_msg5
	call dispstr
	mov bx, ax
	mov al, bh
	call toasc
	mov al, bl
	call toasc
	mov dl, 'h'
	mov ah, 02h
	int 21h

	pop si
	pop cx
	pop bx
	pop dx
	pop ax
	ret
count_digits endp

; 输出al寄存器的值
toasc proc
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

	pop dx
	pop cx
	pop bx
	pop ax
	ret
toasc endp

main:
	mov ax, data
	mov ds, ax
main_proc1:
	mov dx, offset lint_msg3
	call dispstr
	call read_digital_string
	cmp ax, 0
	jne main_proc2
	call digit2num
	call num2bin
	mov dx, offset lint_msg2
	call dispstr
	mov dx, offset binary_string
	call dispstr

	mov dx, offset lint_msg6
	call dispstr
	call num2hex_and_disp

	jmp main_proc1
main_proc2:
	mov dx, offset lint_msg4
	call dispstr
	call count_digits
	mov ah, 4ch
	int 21h
code  ends
end main
