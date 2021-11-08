     AREA     appcode, CODE, READONLY
     EXPORT __main
     IMPORT printMsg
     ENTRY 

__main FUNCTION
     MOV R0, #00 ;largest number
     MOV R1, #04
     MOV R2, #07
     MOV R3, #05

     CMP R1, R2
     MOVLT R0, R2
     MOVGE R0, R1

     CMP R0, R3
     MOVLT R0, R3

     BL printMsg

STOP B STOP
     ENDFUNC

     END