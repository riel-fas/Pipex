# Pipex Project

![Pipex Logo](https://via.placeholder.com/200x50?text=Pipex+Logo)  
*Your Shell Piping Simulation*

Welcome to the **Pipex** project for the 1337 School curriculum! This project aims to create a program that simulates shell piping and file redirection, implementing core system-level programming concepts in C.

---

## 🚀 Project Overview

The **Pipex** project simulates the functionality of shell piping, handling processes, file descriptors, and redirection. The program allows multiple commands to be executed in sequence, where the output of one command is passed as input to the next, just like using the `|` operator in a shell.

**Key Concepts Covered:**

- **System Calls**: `pipe()`, `fork()`, `exec()`
- **File Descriptors**: Input/Output redirection
- **Process Management**: Parent and child processes

---

## ⚡ Features

- **Pipe Handling**: Simulates piping between processes.
- **File Redirection**: Supports input and output redirection to/from files.
- **Error Management**: Graceful error handling with clear messages.
- **Flexible Execution**: Supports multiple commands and argument parsing.

---


   [Infile] -> [cmd1] -> [pipe] -> [cmd2] -> [Outfile]
   (Input)    (Command 1)  (Pipe)   (Command 2)  (Output)
