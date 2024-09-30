# Customizing CP/M, Application Programs, and Special Memory Areas

---

## **Introduction**

Welcome to the presentation on three key topics from CP/M (Control Program for Microcomputers):
1. Customizing CP/M
2. Application Programs
3. Special Memory Areas

Let's dive deep into each of these sections and explore how CP/M was a revolutionary operating system for microcomputers.

---

## **1. Customizing CP/M**

**Overview:**
- CP/M had to be adapted to different hardware environments because each computer had unique hardware setups.
- The process of adapting the system to the hardware, known as system-to-hardware interfacing, only needed to be done once for each system.
- Once interfaced, assembly language programmers could write programs that would work on any CP/M-compatible system.

**Key Points:**
- **User-to-System Conventions**: CP/M abstracts hardware-specific details so users don’t need to modify their programs for different hardware.
  - Disk and I/O access is handled via a single entry point, making it portable.
  - This makes the operating system easy to use for writing assembly language programs.

**Important Reminder:**
- CP/M allows developers to write programs that are hardware-agnostic, meaning they run on any system with CP/M without requiring modification.

![image](https://github.com/user-attachments/assets/fd0fef7e-1d54-4185-afc0-3c6517f0d22d)


---

## **2. Application Programs**

**Overview:**
- CP/M loads and executes user programs in an area of RAM called the Transient Program Area (TPA).
- All non-system software (user programs) are referred to as application programs.

### **Transient Program Area (TPA)**:
- The TPA begins at a fixed address in RAM and includes all available memory not used by CP/M.
- **Functionality**: Allows user programs to run without affecting the core operating system.

### **Memory Distribution:**
- The firmware monitor and CP/M itself occupy some parts of memory.
- Only the remaining part, the TPA, is available for user programs.

**Important Tools**:
- **CP/M Editor (ED)**, **Assembler (ASM)**, **Loader (LOAD)**, and **Debugger (DDT)** help in writing and debugging programs that run within the TPA.


---

## **3. Special Memory Areas**

**Overview:**
- Specific areas of memory are reserved for system operations such as interrupt vectors, which handle hardware communication.
- The lowest addresses in RAM are reserved for vectors, which perform important CPU functions such as jumping to specific routines (unconditional jump instructions).

### **Interrupt Vectors**:
- These vectors occupy only 256 bytes of memory but play a crucial role in handling system interrupts.
- The Z80 and 8085 microprocessors added additional interrupt vectors.

### **Buffer Areas**:
- Directly above the vector space, there are small buffer zones used for interfacing user programs with the CP/M operating system.
- CP/M ensures that user programs don't interfere with these critical memory spaces.

### **Memory Map**:

```plaintext
|----------------------------|
|       PROM (Firmware)       |
|----------------------------|
|     Unused Address Space    |
|----------------------------|
|       Monitor RAM           |
|----------------------------|
|     CP/M Operating System   |
|----------------------------|
|   Transient Program Area    |
|----------------------------|
|         Buffers             |
|----------------------------|
|        Vectors (64 bytes)   |
|----------------------------|
