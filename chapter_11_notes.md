# Chapter 11: Learning by Doing
## Introduction:
- This chapter transitions from foundational concepts to practical assembly language programming
- Chapter focus is on:
    - Writing and editing programs in CP/M
    - Using tools like ED aka Editor, ASM aka Assembler, and LOAD
    - Learning through step-by-step programming exercises

## Purpose:
- Teach assembly language programming through a hands-on approach
- Enable understanding of:
    1. Writing code using ED editor
    2. Assembling programs into "executables"
    3. Debugging and running programs in CP/M

## Getting Started with ED:
1. **What is ED?**
    - A basic text editor in CP/M for writing and editing assembly programs
    - Simple commands allow entry, correction, and saving of text files

2. **Setting Up:**
    - Load CP/M and insert a disk containing `ED.COM` (Text editor), `ASM.COM` (Converts source code in the .ASM file into object code), `LOAD.COM` (Converts the .HEX file into binary executable file (.COM)), and `DDT.COM` (Debugging tools)
    - Start ED with: `ED Test.ASM`
        - Creates a new file called `TEST.ASM`
        - Displays the `*` prompt in command mode

3. **Disabling Line Numbering:**
    - Command: `-Y`
    - This ensures alignment with examples in the book by turning off automatic line numbering

4. **Entering Input Mode:**
    - Command: `I` + `CR` (Carriage Return)
    - Moves cursor to next line for entering text
    - Example entry:
    ```assembly
    BDOS EQU 5
    WCONF EQU 2
    ORG 100H
    MVI C, WCONF
    MVI E, '$'
    CALL BDOS
    JMP 0
    END
    ```

## Programming Workflow:
1. **Writing Code:**
    - Use `ED` to create `.ASM` files
    - Commands like `Control Z` for exiting input mode and `Control I` (Tab) for alignment
2. **Assembling Code:**
 
