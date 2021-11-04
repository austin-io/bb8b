# bb8b
The Bare Bones 8-Bit computer emulator.

## About
The bb8b computer is an emulator of a simple 8 bit logic gate computer made by Austin Poberezhnik. The emulator features 16 instructions, 32 bytes of RAM, and 2 General purpose Registors.

## Instruction set

```
0.  HLT: The Halt instruction stops execution of the program
1.  LDA: The Load A instruction takes in 1 argument, an address, and stores the value at that address into the A Registor.
2.  LDB: The Load B instruction takes in 1 argument, an address, and stores the value at that address into the B Registor.
3.  CTA: The C to A instruction transfers the contents of the accumulator, or C Registor, into the A registor.
4.  STA: The Store A instruction takes in 1 argument, an address, and stores the value from the A Registor to the location in memory.
5.  STB: The Store B instruction takes in 1 argument, an address, and stores the value from the B Registor to the location in memory.
6.  ADD: The Addition instruction stores the Sum of the A and B Registors in the C Registor.
7.  SUB: The Subtraction instruction stores the Difference of the A and B Registors in the C Registor.
8.  AND: The And instruction stores the Bitwise And result of the A and B Registors in the C Registor.
9.  OR : The Or instruction stores the Bitwise Or result of the A and B Registors in the C Registor.
10. NOT: The Not instruction stores the Bitwise Not result of the A and B Registors in the C Registor.
11. XOR: The Xor instruction stores the Bitwise Xor result of the A and B Registors in the C Registor.
12. JE : The Jump if Equal instruction takes in 1 argument, an address, and jumps to it if the A and B Registors are equal.
13. JC : The Jump if Carry instruction takes in 1 argument, an address, and jumps to it if the A and B Registors when subtracted set the Carry bit (B - A).
14. JZ : The Jump if Zero instruction takes in 1 argument, an address, and jumps to it if the A Registor is Zero.
15. Jmp: The Jump instruction takes in 1 argument, an address, and jumps to it unconditionally.
```

## Compilation
No dependencies. Simply run:
```
make
```
The output file will be in the `build/` folder.
