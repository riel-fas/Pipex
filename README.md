# 📡 Pipex Project

<div align="center">
    <svg xmlns="http://www.w3.org/2000/svg" width="600" height="200" viewBox="0 0 600 200">
        <rect width="600" height="200" fill="#2c3e50"/>
        <text x="300" y="100" text-anchor="middle" fill="white" font-size="48" font-family="Arial, sans-serif">
            PIPEX
        </text>
        <text x="300" y="150" text-anchor="middle" fill="#bdc3c7" font-size="24">
            Unix Pipe Simulator
        </text>
    </svg>
    <br>
    <svg xmlns="http://www.w3.org/2000/svg" width="100" height="100" viewBox="0 0 100 100">
        <rect width="100" height="100" fill="#00BAF2"/>
        <text x="50" y="60" text-anchor="middle" fill="white" font-size="24">42</text>
    </svg>
    <svg xmlns="http://www.w3.org/2000/svg" width="100" height="100" viewBox="0 0 100 100">
        <rect width="100" height="100" fill="#1A1A1A"/>
        <text x="50" y="60" text-anchor="middle" fill="white" font-size="20">1337</text>
    </svg>
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
