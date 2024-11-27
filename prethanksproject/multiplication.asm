; MULTIPLY TWO NUMBERS PROGRAM
; PROGRAM WILL ONLY PRODUCE PRODUCTS WHICH ARE SINGLE DIGITS
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

; Carriage Return and Line Feed Routine
CCRLF:  MVI     A,CR
        CALL    CO
        MVI     A,LF
        JMP     CO

; Print Message Pointed to by HL to Console
COMSG:  MOV     A,M     ; Get a character
        ORA     A       ; Check if zero
        RZ              ; Return on zero
        CALL    CO      ; Else output the character
        INX     H       ; Point to the next character
        JMP     COMSG   ; Repeat

; Multiplication Routine
MULTIPLY:
        MVI     D,00H   ; Clear high byte of result
        MVI     E,00H   ; Clear low byte of result
MLOOP:  MOV     A,C     ; Check multiplier (C)
        CPI     00H     ; If multiplier is zero, we're done
        JZ      MDONE

        MOV     A,E     ; Add multiplicand (B) to result (E)
        ADD     B
        MOV     E,A     ; Store result low byte
        JC      INCHIGH ; If carry, increment high byte

        JMP     DECMULT ; Decrement multiplier

INCHIGH:
        INR     D       ; Increment high byte of result
        JMP     DECMULT

DECMULT:
        DCR     C       ; Decrement multiplier
        JMP     MLOOP

MDONE:
        RET

; Display Result Routine - Fixed Version
SHOWRES:
        LXI     H,MSG3    ; Load the message pointer
        CALL    COMSG     ; Display result message
        
        MOV     A,D       ; Move high byte of result to A
        CPI     00H       ; Compare with 0
        JZ      ONLYLOW   ; If high byte is zero, jump to only print low byte

        CALL    HEXOUT    ; Output high byte if not zero
        MVI     A,':'     ; Separator
        CALL    CO

ONLYLOW:
        MOV     A,E       ; Low byte of result
        CALL    HEXOUT    ; Output low byte
        CALL    CCRLF     ; New line
        RET

; Convert a Number to Hexadecimal
HEXOUT: ANI     0F0H    ; Mask high nibble
        RRC             ; Shift right 4 bits
        RRC
        RRC
        RRC
        CALL    TOHEX   ; Convert to ASCII
        CALL    CO      ; Output high nibble
        MOV     A,E     ; Restore full byte
        ANI     0FH     ; Mask low nibble
        CALL    TOHEX   ; Convert to ASCII
        CALL    CO      ; Output low nibble
        RET

; Convert Nibble to ASCII
TOHEX:  ADI     30H   ; Add '0'
        CPI     3AH     ; If > '9'
        JC      TRET
        ADD     7H    ; Convert to 'A'-'F'
TRET:   RET

; Get a Single Digit Number (ASCII to Binary)
GETNUM: CALL    CI  
        CPI     CTRLZ
        JZ      RBOOT
        SUI     '0'     ; Convert ASCII to binary
        RET

; Stack Setup
        DS      64      
STAK:   DB      0       

; Memory for Result Buffer
        DS      2       ; Space for high and low result bytes
RESULT: DB      0

        END