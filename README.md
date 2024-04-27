Simple Shell Project
Description
This project is a simple implementation of a Unix-like command line interpreter, or shell. It is capable of reading user commands from standard input, parsing them, and executing them as separate processes. This shell supports basic command execution and process management.

Authors
Steven Rosario
Jose Mendez
Luis Soto
Features
Command line input through standard input.
Execution of commands with arguments.
Basic process management.
Error handling for system calls.
Files
main.c: Contains the main loop of the shell, reading commands and managing the input loop.
shell.c: Implements the core functionality for command parsing and execution.
shell.h: Header file with function declarations and necessary library includes.
Usage
To use this shell:

Compile the project using a C compiler. For example, using gcc:
bash
Copy code
gcc -o simple_shell main.c shell.c
Run the compiled executable:
bash
Copy code
./simple_shell
You can now enter commands at the prompt. To exit, press Ctrl+D (EOF) or type exit.
Contributing
Contributions to this project are welcome. Please follow these steps:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Make your changes and commit them (git commit -am 'Add some feature').
Push to the branch (git push origin feature-branch).
Create a new Pull Request.
License
This project is licensed under the MIT License - see the LICENSE.md file for details.
