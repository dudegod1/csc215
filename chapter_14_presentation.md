# Tricky Techniques: TWOCR, SPMSG, and The End of I/O Subroutines

## Introduction
### Objectives:
- Learn how **TWOCR** and **SPMSG** simplify and optimize assembly programs 
- Understand modular programming priniciples and their applications in console input/output
- Recognize the significance of completing the CPMIO library for advancing CP/M assmbly programming

### Key Takeaways:
1. Subroutines are resuable blocks of code that simplify program design
2. The stack can be leveraged for efficient data handling and message processing
3. The completed I/O subroutine library is the foundation for advanced assembly programming

---

## Section 1: TWOCR - A One-Line Subroutine

### You might be wondering what is TWOCR?
- It is a subroutine that adds **two blank lines** (double line feed) to console output for better readbility

### Why is it Useful?
- It enhances the clarity of error messages and warnings by visually serparating them from other text

### Implementation:
```assembly
TWOCR: CALL CCRLF ; Call CCRLF (Carriage Return Line Feed)
```
- Calls `CCRLF` twice in sequence:
    - The first `CCRCLF` creates a new line
    - The return from `CCRLF` calls upon another line feed

### Benefits:
1. Simplifies code by reducing repetitive calls
2. Makes sure the double-spacing for messages are consistent
3. Improves console outp[ute readability with little effort

### Example:
```assembly
CALL TWOCR ; Adds 2 blank lines
CALL SPMSG ; Displays a message
DB 'This is a test message', 0
```
### Output:
```assembly
empty line
empty line
This is a test message
```

---

## Section 2: SPMSG - Displays In-Line Messages

### Now what is SPMSG?
- It is a subroutine for displaying **in-line messages** directly in the program code
- Eliminates need for pre defined message buffers

### How does it work??
1. Write `CALL SPMSG` followed by the message in the `DB` directive:
```assembly
CALL SPMSG
DB 'Message to display', 0
```

### Output:
```assembly
Message to display
```

### Why does SPMSG make you life easier?
```assembly
LXI H, MSG ; Load address of MSG into HL
CALL PRINT ; Print message subroutine
...
MSG: DB 'Message to display', 0
```

2. The subroutine fetches and outputs each character from memory until a zero byte is encountered

### Benefits:
1. Keeps messages close to the related program logic, improving code readability
2. Removes need for manually defined message buffers
3. Saves memory and reduces register usage         
