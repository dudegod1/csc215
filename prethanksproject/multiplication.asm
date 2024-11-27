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