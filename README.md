<p align="center"> 
<img src="https://img.shields.io/badge/-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr))"> 
<img src="https://img.shields.io/badge/1337-000000?style=for-the-badge&logo=1337&logoColor=white)](https://1337.ma))">  
<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)">
</p> 
<h1 align="center">🚀 Pipex 🚀</h1> 

## 🚀 Project Overview

Pipex is a challenging system programming project that simulates the behavior of shell pipe (`|`) functionality in Unix/Linux systems. The goal is to create a program that replicates the pipe mechanism by executing multiple commands and managing their input/output streams.

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
