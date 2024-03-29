P8255_A    	equ		0270H    		
P8255_B    	equ		0271H
P8255_C    	equ		0272H
P8255_MODE 	equ		0273H

_STACK	SEGMENT	STACK
		DW	100	DUP(?)
_STACK	ENDS

_DATA	SEGMENT WORD	 PUBLIC 'DATA'
_DATA	ENDS

CODE		SEGMENT
ASSUME CS:CODE, DS:_DATA, SS:_STACK
START	PROC	 NEAR
		MOV	AX, _DATA
        	MOV DS, AX


INIT:
		MOV	DX,P8255_MODE
		MOV	AL,10001001B
		OUT	DX,AL
INPUT:		
		MOV	DX,P8255_C
		IN	AL,DX
		CMP	AL,01H
		JZ	Q1
		CMP	AL,02H
		JZ	Q2
		JMP	INPUT
Q1:
		MOV	AX, 0FFFEH
A1B:
		CALL	DELAY
		MOV 	DX,P8255_A		
		OUT	DX,AL
		ROL	AX,8
		MOV 	DX,P8255_B		
		OUT	DX,AL
		ROL	AX,8		
		ROR	AX,1
		CMP	AX, 0FFFEH
		JNE	A1B		
		JMP	INPUT		
Q2:
		MOV	AX, 0F0FH
A2B:
		CALL	DELAY
		MOV 	DX,P8255_A		
		OUT	DX,AL
		ROL	AX,8
		MOV 	DX,P8255_B		
		OUT	DX,AL	
		ROL	AX,8	
		ROL	AX,1
		CMP	AX, 0F0FH
		JNE	A2B		
		JMP	INPUT
	
Delay 	PROC NEAR				
Delay1:	
XOR	CX,CX					
		LOOP	$
		RET
Delay	ENDP
START	ENDP		
CODE		ENDS		
END		START


