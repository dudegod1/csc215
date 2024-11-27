; MULTIPLY TWO NUMBERS PROGRAM
CR      EQU     0DH     
LF      EQU     0AH     
CTRLZ   EQU     1AH     

; CP/M BDOS Functions
RCONIN  EQU     1       
WCONOUT EQU     2       

; CP/M Addresses
RBOOT   EQU     0       
BDOS    EQU     5      
TPA     EQU     100H    

        ORG     TPA     

; Main Program Start
START:  LXI     SP,STAK ; Set up user's stack
START1: CALL    CCRLF   ; Start a new line
        LXI     H,SIGNON ; With sign-on message
        CALL    COMSG
START2: LXI     H,MSG1  ; MSG1 prompts for first number
        CALL    COMSG   
        CALL    GETNUM  ; GET FIRST NUMBER
        MOV     B,A     ; STORE IN B REGISTER
        CALL    CCRLF

START3: LXI     H,MSG2  ; MSG2 prompts for second number
        CALL    COMSG   
        CALL    GETNUM  ; GETS THE SECOND NUMBER
        MOV     C,A     ; STORE IN REGISTER C
        CALL    CCRLF

        CALL    MULTIPLY ; MULTIPLY NUMBERS
        CALL    SHOWRES ; SHOW THE RESULT
        JMP     START2   ; RESTARTS PROGRAM

; Messages
SIGNON: DB      'Multiplication Program (CTRL + Z to Exit)',CR,LF,0
MSG1:   DB      'Enter the first number (0-9): ',CR,LF,0
MSG2:   DB      'Enter the second number (0-9): ',CR,LF,0
MSG3:   DB      'The result is: ',CR,LF,0

; Console Character Input Routine
CI:     PUSH    B       ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,RCONIN ; Read function
        CALL    BDOS
        ANI     7FH      ; Mask to 7 bits
        POP     H        ; Restore registers
        POP     D
        POP     B
        RET

; Console Output Character Routine
CO:     PUSH    B       ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,WCONOUT ; Select function
        MOV     E,A     ; Character to E
        CALL    BDOS    ; Output by CP/M
        POP     H       ; Restore registers
        POP     D
        POP     B
        RET