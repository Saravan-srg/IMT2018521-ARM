    AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
     MOV R3,#0
	MOV R0,R3
	BL printMsg

	MOV R4,#1
	MOV R0,R4
	BL printMsg
	
	MOV R6,#00 ;count variable
	
loop
	ADD R5,R3,R4 ;sum of previous two numbers
	MOV R0,R5
	BL printMsg
	MOV R3,R4
	MOV R4,R5
	ADD R6,#01	
	CMP R6,#9 ;prints the first 10 nums of fibo series 
	BNE loop
	
STOP B STOP
    ENDFUNC
    END