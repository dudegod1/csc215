# Chapter 12: Console Input/Output

## Introduction:
- Higher-level and assembly language programs should be structured into blocks
- **Program Blocks:**
    - Each block performs a single function
    - Typically consists of subroutines with one entry and one exit
- **Advantages**
    - Simplifies programming and debugging
    - Encourages modular design

## Subroutine Nesting:
- **Stack Mechanism**:
    - Enables nested subrotuine calls effortlessly
    - Maintains return addresses automatically
- **Flexibility:**
    - Lower-level subroutines handle specific tasks (e.g., single character I/O)
    - Heigher-level subroutines perform complex tasks (e.g., message I/O)

## CPMIO Subroutines:
- **Purpose:**
    - Acts as an interface between user programs and CP/M's BDOS (Basic Disk Operating Systems)
    - Simplifies I/O by preserving user registers while using BDOS calls

## Console Input/Output Subroutines:
1. **CI: (Counsole Input)**:
    - Reads a single ASCII character from the console into the `A` register
    - Masks the 8th bit to ensure only 7 bit ASCII is used

2. **CO: (Counsole Output)**:
    - Sends the character in the `A` register to the console screen
    - Uses CP/M's BDOS call (`WCONF`)

## Functionality:
- Both subroutines:
    - Preserve all registers
    - Utilize BDOS calls for hardway independent operations
    - Provide a foundation for higher level I/O operations (e.g., line buffering)

## CI: Console Input Subroutine:
- **Steps:**
    1. Save registers (`PUSH B`, `PUSH D`, `PUSH H`)
    2. Load `RCONF` into `C` (BDOS read function)
    3. Call BDOS
    4. Mask the 8th bit using `ANI 7FH` to remove parity
    5. Restore registers and return (`POP` operations)

- **Reason for Masking:**
    - ASCII characters only use 7 bits
    - The 8th bit may represent parity, which can vary across devices
