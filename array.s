	AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
    MOV R1, #0x20000000 ; Base address of array
	MOV R2, R1;
	
    MOV R4,#01 ; Element 1
    STR R4, [R2]
	
    ADD R2, #04 
    MOV R4,#2; Element 2
    STR R4, [R2]

    ADD R2, #04
	MOV R4,#3 ; Element 3
    STR R4, [R2]

	ADD R2, #04
    MOV R4,#6 ; Element 4
    STR R4, [R2]

	ADD R2, #04
    MOV R4,#5 ; Element 5
    STR R4, [R2]

    MOV R5,#00
	MOV R3,#05 ; Length of array
	MOV R2,#0x20000000 

Loop CMP R3,#00
	BEQ Print
	LDR R6,[R2]
	CMP R6 ,R5      
    MOVGE R5, R6
	ADD R2,#04
	SUB R3,#01
	B Loop

Print MOV R0,R5
	BL printMsg

STOP B STOP
    ENDFUNC
    END



	