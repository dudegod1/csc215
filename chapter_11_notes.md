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
    - Use `CTRL I` (tab) for alignment in columns
5. **Saving the File**
    - Exit input mode with `CTRL Z`
    - Save file with command: `E`
    - Creates two files:
        - `TEST.ASM`: This is the source code
        - `TEST.BAK`: This is the backup copy

## Editing and Debugging with ED:
1. **Correcting Mistakes While Typing**
    - USE `DEL` or `RUBOUT` to erase the last character
    - The cursor doesn't move back but duplicates the character to indicate deletion

2. **Correcting Mistales After Listing:**
    - USE `B8T` to move the pointer to the start and display the file
    - Replace errors with the substitue command:
        - Exmmple: Replace `MIV` with `MVI`:
            ```plaintext
            SMIV^Z
            MVI^Z
            OLT
            ```

3. ** Reopening Files:**
    - COmmand: `ED TEST.ASM`
    - Append file into the buffer with `#A`

4. **Quitting without Saving:**
    - Command: `Q`
    - Exits ED without writing changes to disk  
