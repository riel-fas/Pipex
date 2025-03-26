# Pipex Project

![Pipex Logo](https://via.placeholder.com/150)  <!-- You can replace this with an actual image link -->

Welcome to the **Pipex** project for the 1337 School curriculum! This project demonstrates your ability to work with processes, piping, and file descriptors in C. The goal is to create a program that simulates the behavior of shell piping using system calls.

---

## Overview

**Pipex** is a program that simulates piping between processes and handles file redirection. It takes the output of one process and pipes it as the input to the next, just like the `|` operator in a shell. This project requires understanding of:

- File descriptors
- `fork()`
- `exec()` functions
- `pipe()`
- Redirection of input and output

---

## Features

- **Pipe Handling**: Simulates the shell's piping mechanism, connecting multiple processes together.
- **File Redirection**: Supports input and output redirection to and from files.
- **Error Handling**: Proper error management and messages for invalid inputs or failed system calls.
- **Processes**: Uses `fork()` to create child processes for executing commands.

---
