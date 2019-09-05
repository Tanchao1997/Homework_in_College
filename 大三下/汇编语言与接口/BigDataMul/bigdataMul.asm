.386
.model flat, stdcall
option casemap : none

includelib msvcrt.lib
include msvcrt.inc

endl equ <0DH,0AH>
.data

numCharA byte 1000 dup(0)
numCharB byte 1000 dup(0)
resultChar byte 2000 dup(0)
numIntA dword 1000 dup(0)
numIntB dword 1000 dup(0)
result dword 2000 dup(0)

inputMsg byte "please input a large number: ",0
szFmt_s byte "%s", 0
szFmt_d byte "%d", 0
szFmt_c byte "%c",0

note byte "Please input any charactor to exit:",endl,0
outputMsg byte "the result is: %s",endl,0
outputMsg2 byte "the result is: %s%s",endl,0

wa dword 1000 dup(0)
lengthA dword 0
lengthB dword 0
lengthC dword 0

radix dword 10
negativeFlag byte 0
negativeImg byte "-"

.code

str2int_reverse proc far C numChar:ptr byte, numInt:ptr dword, len:dword
	mov ecx, len 
	mov esi, numChar
L1:
	movzx eax, byte ptr [esi]
	sub eax, 30H 
	push eax 
	inc esi
	loop L1 

	mov ecx, len
	mov esi, numInt
L2:
	pop eax
	mov dword ptr [esi], eax
	add esi, 4
	loop L2	

	ret
str2int_reverse endp



int2str_reverse proc far C uses eax esi ecx 
	mov ecx, lengthC 
	mov esi, 0 
L1:
	mov eax, dword ptr result[4 * esi] 
	add eax, 30H
	push eax
	inc esi
	loop L1 

	mov ecx, lengthC
	mov esi, 0
L2:
	pop eax
	mov byte ptr resultChar[esi], al 
	inc esi
	loop L2
	
	ret
int2str_reverse endp



getStringALen proc far C uses eax
	.if numCharA == 2DH	
		xor negativeFlag, 1 
		invoke crt_strlen, addr (numCharA + 1) 
		mov lengthA, eax
		invoke str2int_reverse, addr (numCharA+ 1), addr numIntA, lengthA 
	.else 
		invoke crt_strlen, addr numCharA 
		mov lengthA, eax
		invoke str2int_reverse, addr numCharA, addr numIntA, lengthA
	.endif
	ret
getStringALen endp


getStringBLen proc far C uses eax
	.if numCharB == 2DH	
		xor negativeFlag, 1 
		invoke crt_strlen, addr (numCharB + 1) 
		mov lengthB, eax
		invoke str2int_reverse, addr (numCharB + 1), addr numIntB, lengthB 
	.else 
		invoke crt_strlen, addr numCharB 
		mov lengthB, eax
		invoke str2int_reverse, addr numCharB, addr numIntB, lengthB
	.endif
	ret
getStringBLen endp

high_multiply proc far C uses eax ecx esi ebx
	mov ebx, -1
OuterLoop: 
	inc ebx
	cmp ebx, lengthA
	jnb endLoop1 
	xor ecx, ecx
InnerLoop:	
	xor edx, edx
	mov eax, dword ptr numIntA[4 * ebx]
	mul numIntB[4 * ecx] 
	mov esi, ecx
	add esi, ebx 
	add result[4 * esi], eax 
	inc ecx
	cmp ecx, lengthB 
	jnb OuterLoop 
	jmp InnerLoop	
endLoop1:
	mov ecx, lengthA
	add ecx, lengthB
	inc ecx	
	mov esi, offset lengthC
	mov [esi], ecx 

	xor ebx, ebx
CarryCul:
	cmp ebx, ecx
	jnb endLoop2 
	mov eax, result[4  * ebx]
	xor edx, edx
	div radix
	add result[4 * ebx + 4], eax 
	mov result[4 * ebx], edx 
	inc ebx
	jmp CarryCul
endLoop2: 
	mov ecx, lengthC 
MoveZero:
	cmp dword ptr result[4 * ecx], 0
	jnz endwhile1
	dec ecx 
	jmp MoveZero
endwhile1:
	inc ecx 
	mov esi, offset lengthC
	mov [esi], ecx 
	invoke int2str_reverse 
	ret
high_multiply endp

main proc
	invoke crt_printf, addr inputMsg
	invoke crt_scanf, addr szFmt_s, addr numCharA
	invoke crt_printf, addr inputMsg
	invoke crt_scanf, addr szFmt_s, addr numCharB

	invoke getStringALen
	invoke getStringBLen 
	
	invoke high_multiply 

	.if negativeFlag == 1
		invoke crt_printf, addr outputMsg2,addr negativeImg, addr resultChar
	.else 
		invoke crt_printf, addr outputMsg, addr resultChar
	.endif
	invoke crt_printf, addr note
	invoke crt_scanf,addr szFmt_s, addr wa
	ret
	
main endp
end main
