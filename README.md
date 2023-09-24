# Laboratory work #1

This C program allows you to evaluate a mathematical function for a given range of values using different looping techniques, including `for`, `while`, `do-while`, and `goto`. The program takes user input for coefficients `a`, `b`, `c`, as well as the range and step size for the input variable `x`. It then computes and displays the function values for the specified range using each of the looping methods.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Looping Techniques](#looping-techniques)
  - [for Loop](#for-loop)
  - [while Loop](#while-loop)
  - [do-while Loop](#do-while-loop)
  - [goto Statement](#goto-statement)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This program allows you to:

1. Enter coefficients `a`, `b`, and `c` for the mathematical function.
2. Define the range of `x` values using `x1` (start) and `x2` (end).
3. Specify the step size `px` for `x`.

The program then computes and displays the function values for `x` within the specified range using different looping techniques.

## Usage

1. Clone the repository to your local machine and switch to the "Lab-1" branch:

   ```bash
   git clone -b Lab-1 https://github.com/AlexandruRudoi/Computer-Programming.git
   cd Computer-Programming
   ```

2. Compile the C code:

   ```bash
   gcc -o main.c -lm
   ```

   Note: The `-lm` flag is used to link the math library for functions like `log`, `sin`, `cos`, and `pow`.

3. Run the program:

   ```bash
   ./a.exe
   ```

4. Follow the on-screen prompts to enter coefficients `a`, `b`, `c`, as well as the range and step size for `x`.

5. The program will display the computed function values using various looping techniques.

## Looping Techniques

### for Loop

The `for` loop is used to iterate through the specified range of `x` values and compute the function values.

### while Loop

The `while` loop is used to iterate through the specified range of `x` values and compute the function values.

### do-while Loop

The `do-while` loop is used to iterate through the specified range of `x` values and compute the function values. It ensures that the loop body is executed at least once.

### goto Statement

The `goto` statement is used in combination with a label to create a loop. It iterates through the specified range of `x` values and computes the function values.

## Contributing

Contributions to this repository are welcome! If you have any improvements or suggestions for this program or would like to add more features or techniques, please open a pull request. Make sure to follow the existing code style and add appropriate documentation.

## License

This project is licensed under the TUM License.
