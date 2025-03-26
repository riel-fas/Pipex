# 📡 Pipex Project

<div align="center">
    <img src="/api/placeholder/600/200" alt="Pipex Banner" />
    <br>
    <img src="/api/placeholder/100/100" alt="42 Network Logo" />
    <img src="/api/placeholder/100/100" alt="1337 School Logo" />
</div>

## 🚀 Project Overview

Pipex is a challenging system programming project that simulates the behavior of shell pipe (`|`) functionality in Unix/Linux systems. The goal is to create a program that replicates the pipe mechanism by executing multiple commands and managing their input/output streams.

## 🛠 Technologies & Languages

![C Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Unix](https://img.shields.io/badge/Platform-Unix/Linux-green?style=for-the-badge&logo=linux)

## 📋 Project Requirements

- Recreate shell pipe behavior
- Handle multiple command executions
- Manage file inputs and outputs
- Implement error handling
- Use system calls like `fork()`, `pipe()`, `exec()`, etc.

## 🔧 Key Concepts

- Process Creation
- Inter-Process Communication
- File Descriptors
- System Calls
- Error Handling

## 💻 Compilation & Usage

```bash
# Compile the project
make

# Run the program
./pipex input_file cmd1 cmd2 output_file
```

## 📝 Example

```bash
# Mimics: < input.txt grep Hello | wc -l > output.txt
./pipex input.txt "grep Hello" "wc -l" output.txt
```

## 🎯 Project Goals

1. Understand Unix process management
2. Learn system programming concepts
3. Improve low-level programming skills
4. Gain expertise in C programming

## 🚧 Error Handling

- Validate input parameters
- Check file permissions
- Handle command execution failures
- Manage memory leaks

