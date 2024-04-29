# Simple Shell Project

## Description
This project is a simple implementation of a Unix-like command line interpreter, or shell. It is capable of reading user commands from standard input, parsing them, and executing them as separate processes. This shell supports basic command execution and process management.

## Authors
- Steven Rosario
- Jose Mendez
- Luis Soto

## Features
- Command line input through standard input.
- Execution of commands with arguments.
- Basic process management.
- Error handling for system calls.

## Files
- `main.c`: Contains the main loop of the shell, reading commands and managing the input loop.
- `shell.c`: Implements the core functionality for command parsing and execution.
- `shell.h`: Header file with function declarations and necessary library includes.

## Usage
To use this shell:
1. Compile the project using a C compiler. For example, using `gcc`:
   ```bash
   gcc -o simple_shell main.c shell.c
