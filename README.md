<p align="center"> 
<img src="https://img.shields.io/badge/42-Network-black?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAAsTAAALEwEAmpwYAAABiElEQVQ4y2NgGFQggv//CSgoKCgqKioqKSkpKSkpffz48f///f8P0tjR0VHe3t5e29zcXNLc3FzS2NhY0tDQUNLQ0FDS1NRc0traurS1tXVpW1vb0tbW1qVtbW1L29vbl7a3ty9tb29f2tHRsbSjo2Npe3v70s7OzqWdnZ1LBwYGlw4ODi4dGhpaOjQ0tHRkZGTp6Ojo0rGxsaVjY2NLx8fHl46Pjy8dHx9fOjExsXRycnLpzMzM0llg8D8K//37R/Dv3z+Cv3//Evz//5/g+/cfBP/+/Sf4/v0nwe/fvwm+ff9F8OfPX4Kf\n P34T/Pz5i+Dnz98Ev3//Ifj9+y/Bn/2/gAr+ATX+hCr+AVWAqQAW+APU8Aeo4R9Qw19QDf+BGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBr+ATX8A2r4B9TwD6jhH1DDH6CGf0AN/4Aa/gE1/ANq+AfU8A+o4R9Qwz+ghn9ADf+AGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBoYAABhKkjR0SIEzwAAAABJRU5ErkJggg==" alt="42 Network"> 
<img src="https://img.shields.io/badge/1337-Coding-green?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAAsTAAALEwEAmpwYAAABiElEQVQ4y2NgGFQggv//CSgoKCgqKioqKSkpKSkpffz48f///f8P0tjR0VHe3t5e29zcXNLc3FzS2NhY0tDQUNLQ0FDS1NRc0traurS1tXVpW1vb0tbW1qVtbW1L29vbl7a3ty9tb29f2tHRsbSjo2Npe3v70s7OzqWdnZ1LBwYGlw4ODi4dGhpaOjQ0tHRkZGTp6Ojo0rGxsaVjY2NLx8fHl46Pjy8dHx9fOjExsXRycnLpzMzM0llg8D8K//37R/Dv3z+Cv3//Evz//5/g+/cfBP/+/Sf4/v0nwe/fvwm+ff9F8OfPX4Kf\n P34T/Pz5i+Dnz98Ev3//Ifj9+y/Bn/2/gAr+ATX+hCr+AVWAqQAW+APU8Aeo4R9Qw19QDf+BGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBr+ATX8A2r4B9TwD6jhH1DDH6CGf0AN/4Aa/gE1/ANq+AfU8A+o4R9Qwz+ghn9ADf+AGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBoYAABhKkjR0SIEzwAAAABJRU5ErkJggg==" alt="1337 Coding"> 
</p> 
<h1 align="center">🚀 Pipex 🚀</h1> 

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
