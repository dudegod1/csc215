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

## Assembling Programs with ASM:
1. **Purpose:**
    - Converts `.ASM` files into `.HEX` (machine-readable) and `.PRN` (human readable) files
    - Resolves symbolic references and builds object code

2. **Command:**
    - `ASM Test`
    - Output:
        - `TEST.HEX` - The object file
        - `TEST.PRN` - A detailed program listing

3. **How ASM Works:**
    -**Pass 1:** Builds a symbol table of labels and their addresses
    -**Pass 2:** Resolves forward references and generates object code
    - Example Listing:
    ```assembly
    0005 BDOS EQU 5
    0002 WCONF EQU 2
    0100 ORG 100H
    0100 0E02 MVI C, WCONF
    0102 1E24 MVI E, '$'
    0104 CD0500 CALL BDOS
    0107 C30000 JMP 0
    010A END
    ```

4. **Error Handling:** 
    - Errors in lables or instructions appear as messages during assembly
    - Forward references (e.g., defining symbols at the end) require a second pass

## Loading and Running Programs:
1. **Purpose:**
    - Converts `.HEX` files into executable `.COM` files
    - Loads the binary image into the memory

2. **COmmand:**
    - `LOAD TEST`
    - Output:
        - `TEST.COM`: The executable file
3. **Executing Programs:**
    - Run the program by entering its name, in this case: `TEST`
    - Expected output:
        - Displays `$` on the console and returns to the command prompt

4. **Intel HEX Format:**
    - Used for `.HEX` files:
        - ASCII-based and portable between systems
        - Includes checksum for error detection  
