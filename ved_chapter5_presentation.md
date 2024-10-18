# Organization Of CP/M

This section discusses some items that the operating system needs, including access to programs at the most primitive level that communicate with the physical devices through the computer hardware. These driver routines are prerequisites to running CP/M and operate at the lowest level of all software in a computer system.

## Disk and I/O access primitives

### Loader program

In the first section, we learned...

1. how data is stored on a disk.
2. how a loader program somewhere in ROM is used to load the operating system in to the proper place in RAM.

The loader program answers a certain dilemma:

When a computer is turned off, no software can run on it. However, for the computer to start working, some software had to tell it to do so. Therefore, how do we get software from software if there is no software?

The answer is a **loader program**: a small program which pre-exists somewhere in the computer's memory which can get the operating system off the disk and into memory.

- The loader is available when the power is first turned on AND when the operator hits the RESET switch.
- The PROM-based loader contains some routines to allow it to access the disk.
- These include positioning the head of the correct disk drive to the correct track and sector where the beginning of the operating system will be found, and then load the system into RAM.

### Primitive functions in CP/M

- Similarly, these same routines will be needed by the operating system to perform the same primitive functions.
- **To adapt CP/M to a particular computer involves connecting the proper functions in CP/M to the proper disk primitives in PROM.**
- The same applies for I/O device accesses.
- The **Customized Basic Input/Output System (CBIOS)** is an area set aside in CP/M to include the proper I/O device access primitives for the computer.

### Vectors

**An area within CP/M is also set aside for vectors that point to disk and I/O acess primitives.**

Here is a diagram of those vectors:

![Diagram of vectors](ch_5_image1.png)

And here is a table of them:

![Table of vectors continued](ch_5_image2.png)

#### Booting vectors

- These vectors are **three byte jump instructions**, such as JMP BOOT, JMP WBOOT, et cetera.
- The addresses shown in the table are absolute addresses for a 16 kilobyte version of CP/M.
- The first vector points to routines that get the OS running after the PROM loader has bootstrapped in the CP/M system, and will be jumped to from the PROM loader.
- CP/M is activated when the Console Command Processor (CCP) is activated from the WBOOT vector above.
- CCP is what prompts the user with the ">" character and then waits for a command to be entered from the `CON:` device.

#### I/O vectors

- The next six vectors enable the CCP, other portions of CP/M, and user programs in the TPA to be able to communicate with physical I/O devices.
- These vectors point to driver subroutines that decode IOBYT and bridge the gap between software and physical devices.

#### Disk vectors

- The seven vectors which follow are disk vectors.

To adapt CP/M to a new computer, all one must do is provide the loader in PROM and the 15 routines to be accessed through vectors. This has already been done for us, so we need not worry about it.

## BDOS——The Basic Disk Operating System

### Storage units

- Disk storage in CP/M is organized in **records, blocks and groups**.
- A **record** stores **128 bytes**. It is the basic disk storage unit, and derives from the old days of computing when floppy disk sectors held 128 bytes of data.
- A **block** consists of **2 records**, or **256 bytes** in total.
- A **group** stores **8 records**, which totals to **1 kilobyte**.

### Abstraction

- BDOS abstracts the details of file handling within CP/M.
- All the user has to do is tell the system to read FILENAME.TYP into the TPA.
- BDOS will then search the directory for the named file.

### File control block (FCB)

- When BDOS searches the directory for a file, the information it retrieves is stored in a **file control block (FCB)** within the TPA.
- The FCB is a data structure used by the BDOS to store hold essential information about a file, such as its name and type, location on disk, size and disk drive number.

### The catch

- All of this convenience, however, comes at a price.
- The smallest unit of space on a disk that CP/M can allocate is a one kilobyte group.
- Hence, if a file is just one byte long, it will still take up one kilobyte on the disk.
- If the file contains 1K + 1 to 2048 bytes, it will take up two groups, or two kilobytes or 2K of disk space.

### Dynamic allocation

- BDOS also remembers what files have been erased using FCBs so that their disk space can be reused.
- User programs can ask BDOS to look for files in the folder, read them into RAM, write them from RAM to disk, or erase them.
- The computer operator can also perform such operations through PIP or the CCP.

### Special error

- One last thing to note about BDOS is the special error: `BDOS ERR ON B: BAD SECTOR`.
- This error means that BDOS encountered a checksum error while tring to read or write to a sector in disk drive B.
- When BDOS first encounters this error, it will try over and over to read or write to the sector. After a few trys, it will give up and display that message.
- If you encounter this error, you can reboot the system with a warm start using the command `CTRL C`.

### Another special error

- If you ever see the BDOS error message `BDOS ERR ON R: SELECT`, or this message with any other **illegal** drive specified, it means your program is totally lost, and has garbaged the **drive select byte** at location 4 in RAM.
- The **drive select byte** is a specific memory location in RAM which tracks information about the disk drive which the system or program is on. This byte tells CP/M which drive (e.g. `A:` or `B:`) to read or write to.

## CBIOS - The Customized Basic Imput/Output System

### Fragmented Organization

- The reason why the organization of CP/M seems so fragmented and complicated is because it was meant to use the available resources of a simple 16K bytes of RAM to their fullest.
- Although the organization seems fragmented, it's actually encapsulated and abstracted into clean, simple parts, similar to objects in object-oriented programming.
- Access to all disks and I/O devices can be made through the single location 5 vector pointing to the BDOS entry point, similar to the constants of a class.

### CBIOS

- The 15 other CBIOS vectors are grouped in one place and have enough memory space above them to incorporate customized drivers that tailor CP/M to run on your hardware.
- Thus, the I/O system of CP/M can easily be customized, which is why it is called "custom."

The following is a memory map for version 1.4 of CP/M:

![CP/M v1.4 memory map](ch_5_image3.png)

- CBIOS contains all the I/O drivers shown in the map above.

### IOBYT

- A term which the book has thrown around many times but has never defined effectively is IOBYT.
- **IOBYT** (input/output byte) is essentially a configuration byte used by the system to map logical devices to physical devices.

#### How it's implemented

In the map above, IOBYT has not been implemented. However, if it is, it takes the following format:

- Each logical device can have more than one physical device mapped to it;
- So, each logical device is assigned a two-bit field in the IOBYT.
- These two bits are used to represent which physical device should be mapped to the logical device.
- When a driver needs access to a device, it reads the IOBYT, isolates the specific bits for that logical device, and decodes them to find out which physical device is currently selected.

This is shown in the diagram below:

![IOBYT device selector diagram](ch_5_image4.png)

### Device names

With your CP/M system disk in the current drive, enter the CCP command: `STAT VAL:` and you should see the following display:

```txt
CON: = TTY: CRT: BAT: UC1: 
RDR: = TTY: PTR: UR1: UR2: 
PUN: = TTY: PTP: UP1: UP2: 
LST: = TTY: CRT: LPT: ULI:
```

produced by the CP/M transient utility STAT.

- This shows all of the logical device names used by CP/M along with the physical devices that connect to CP/M as those names.

[Link to Ved's section of the presentation](https://github.com/dudegod1/csc215/blob/main/ved_chapter5_presentation.md)

## CCP——The Console Commmand Processor

- Once CP/M has been loaded into RAM, the WBOOT vector starts the CCP, or console command processor.
- The CCP prompts the user with the current disk drive and a greater than symbol: `A>`.
- CCP expects commands either consisting of the name of a resident function OR the FILENAME of a .COM file on the disk.
- FILENAMEs can be preceeded by `B:` or any other drive designator if they are in a different disk than the current one.

### An example

- Suppose there is a program named COMPARE that compares the contents of two disk files and displays any differences found between them.
- To keep the display from scrolling off the screen faster than the operator can see it, the operator can enter a directive to tell the program to pause following the display of each difference.
- This program is invoked by typing `COMPARE B:TEST.ASM B:TEST.BAK PAUSE` to see all the updates made to his program TEST following the last edit session.

## Resident functions

- **Resident functions** are utility routines which reside permanently in the system area in the computer memory.
- Resident functions can be executed instantaneously instead of being loaded into RAM from disk.

Here is a table of the resident functions:

![Table of all the resident functions of CP/M](ch_5_image5.png)

- The most frequently used resident function is **DIR**, used to display files on your disk.

### DIR

- DIR is usually used on its own but can also be followed by a filename to verify the presence of certain file(s).

### ERA

- ERA can be invoked with the same options that work for DIR.
- The following command, for example, will clear your disk of all backup files: `ERA B:*.BAK`.
- **ERA** stands for *erase*, by the way.

### SAVE

- The SAVE command can be used to create an empty file.
- For example, the command `SAVE 12 TEST.COM` creates a file containing 12 memory pages, with each memory page being a block of 256 bytes.

### REN

- The REN command allows you to rename a file.
- The command `REN B:GOODPROG.COM=B:TEST.COM` changes the name of the file `TEST.COM` to `GOODPROG.COM`.
- Note that when doing so, the programmer must also remember to rename `TEST.ASM`.

### TYPE

- The final resident command, TYPE, when given a specific filename, will type out the contents of the named file onto the console.

[Link to Ved's section of the presentation (again)](https://github.com/dudegod1/csc215/blob/main/ved_chapter5_presentation.md)

## Transient Utilities

- Transient utilities are non-resident programs that are loaded from disk as `.COM` files and are executed in the same manner as user programs.
- The `STAT` command, often used to check disk space and file statistics, shows why it's a transient utility (too large for resident memory).
- Other commands like `STAT LST:=LPT:` reassign devices like the logical list device to a physical device.
- It is noted that further transient utilities will be covered later, and there's no need to memorize all commands upfront.

## User Programs

- The transient utilities and user programs are both `.COM` files executed from the Transient Program Area (TPA).
- When executing a user program, CCP parses the command line and loads filenames into control blocks.
- CCP services help organize the program commands, making the execution of user programs efficient.
- The chapter hints at further content about maximizing the use of CP/M's services in the next section.
