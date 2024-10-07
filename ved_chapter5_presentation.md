# CCP - The Console Command Processor

## Summary
- The CCP is part of the CP/M system that interacts with the user to receive commands. 
- Upon booting CP/M into RAM, CCP prompts the user with a command line using the active drive symbol (e.g., `A>`).
- Commands can either be a resident function or a `.COM` file from the disk. If the `.COM` file is on another drive, the drive letter can be specified.
- Options, if required, follow the command or filename, and multiple options are separated by spaces.
- For unrecognized commands, CCP assumes it's a `.COM` file and prepares a buffer to execute the file.
- Example command: `COMPARE B:TEST.ASM B:TEST.BAK PAUSE` helps the operator compare disk files and pauses the output for easier viewing.

---

# Transient Utilities

## Summary
- Transient utilities are non-resident programs that are loaded from disk as `.COM` files and are executed in the same manner as user programs.
- The `STAT` command, often used to check disk space and file statistics, shows why it's a transient utility (too large for resident memory).
- Other commands like `STAT LST:=LPT:` reassign devices like the logical list device to a physical device.
- It is noted that further transient utilities will be covered later, and there's no need to memorize all commands upfront.

---

# User Programs

## Summary
- The transient utilities and user programs are both `.COM` files executed from the Transient Program Area (TPA).
- When executing a user program, CCP parses the command line and loads filenames into control blocks.
- CCP services help organize the program commands, making the execution of user programs efficient.
- The chapter hints at further content about maximizing the use of CP/M's services in the next section.
