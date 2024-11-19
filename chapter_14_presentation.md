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

