# Laboratory work #5

This C program implements a stack data structure with a menu-driven interface. It allows you to interact with the stack by selecting various operations, such as pushing data onto the stack, popping data from the stack, peeking at the top element, and more. The program also provides color-coded text output for a user-friendly experience.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Data Types](#data-types)
- [Compilation](#compilation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This program introduces you to the stack data structure, which follows the Last-In, First-Out (LIFO) principle. It allows you to perform various stack operations through a menu-driven interface, making it easy to understand and use.

## Features

### 1. Push Data

Allows you to push data of different types (integers, characters, floats, or user-defined structures) onto the stack.

### 2. Pop Data

Pops and displays data from the top of the stack.

### 3. Peek at Data

Displays the data at the top of the stack without removing it.

### 4. Update Maximum Stack Size

Enables you to change the maximum size of the stack.

### 5. Check if Stack is Full

Checks if the stack is full and provides feedback.

### 6. Check if Stack is Empty

Checks if the stack is empty and provides feedback.

### 7. Exit

Exits the program gracefully.

## Data Types

The program uses the following data types:

- **Integer (MY_INT):** Represents an integer data type.
- **Character (MY_CHAR):** Represents a character data type.
- **Float (MY_FLOAT):** Represents a floating-point data type.
- **User-Defined Structure (MY_USER_STRUCT):** Represents a user-defined structure containing an integer and a character array.

## Usage

1. **Compilation:** Compile the C code using your preferred C compiler. 

   ```bash
   gcc stack_program.c -o stack_program
   ```

2. **Run the Program:** Execute the compiled program.

   ```bash
   ./stack_program
   ```

3. **Follow the Menu:** The program will display a menu, and you can select operations by entering the corresponding option number.

## Compilation

No special dependencies are required for compiling and running this program. The provided source code should work on most systems with a C compiler.

## Contributing

Contributions to this program are welcome! If you have suggestions for improvements, additional features, or bug fixes, please consider opening a pull request. Your contributions can enhance the functionality and user experience of the program.

## License

This project is licensed under the TUM License.
