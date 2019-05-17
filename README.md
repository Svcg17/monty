# monty
# Stacks, Queues - LIFO, FIFO
### Objectives
Creation of an interpreter for Monty ByteCodes files.
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
### Opcode Implementations
Opcode | Description | Function name
-- | -- | --
`push` | Pushes an element to the stack | `_push`
`pall` | Prints all the values on the stack | `_pall`
`pint` | prints the value at the top of the stack | `_pint`
`add` | Adds the top two elements of the stack | `_add`
`pop`| Removes the top element of the stack | `_pop`
`swap` | Swaps the top two elements of the stack | `_swap`
`nop` | Doesn't do anything | `_nop`
`sub` | Subtracts the top two elements of the stack | `_sub`
`div` | Divides the top two elements of the stack | `_div`
`mul` | Multiplies the top two elements of the stack | `_mul`
`mod` | Uses module to recieve the remainder of the top two nodes into one | `_mod`
### Usage
`./monty bytecodes/00.m`
### Example
```
vagrant@vagrant-ubuntu-trusty-64:~/0x18-stacks_queues_lifo_fifo$ cat bytecode/07.m 
push 1
push 2
push 3
pall
vagrant@vagrant-ubuntu-trusty-64:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecode/07.m 
3
2
1
```
### Files
Files | Description
-- | --
`main.c` | Main file where file is given from command line and passed to helper functions
`CocoPod.c` | Opens a file, gets each line and parses through every word (tokenizes).
`getCoco.c` | Compares command with struct and calls it's function accordingly.
`opcode.c`  | Contains functions _push, _pall, _pint and _add (used in struct).
`2_opcode.c`  | Contains functions _pop, _swap, _nop(used in struct) and print_errrors for error handling.
`3_ops.c`  | Contains functions _sub, _div, _mul and _mod (used in struct).
`monty.h` | Header file with function prototypes and structs.

### About
Created on `Ubuntu 14.04 LTS`. Compiled with `gcc 4.8.4`, using flags: `-Wall -Werror -Wextra and -pedantic`
Used Betty Style Code.
### Authors
[Geoge Solorio](https://github.com/GeorgeSolorio) - [@SimplerIsBtr](https://twitter.com/SimplerIsBtr) and [Sofia Cheung](https://github.com/svcg17) - [@sofivism](https://twitter.com/sofivism) at Holberton School (http://holbertonschool.com).
