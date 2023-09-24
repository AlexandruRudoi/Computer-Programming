# Laboratory work #3

This repository focuses on Two-Dimensional Array Operations and Processing in C. It includes functionalities to create, sort, and convert matrices into spiral forms.

## Table of Contents

- [Introduction](#introduction)
- [Matrix Manipulation](#matrix-manipulation)
  - [Generate Matrix](#generate-matrix)
  - [Create Matrix](#create-matrix)
  - [Print Matrix](#print-matrix)
- [Sorting and Transformation](#sorting-and-transformation)
  - [Bubble Sort](#bubble-sort)
  - [Matrix to Vector](#matrix-to-vector)
  - [Vector to Spiral Matrix](#vector-to-spiral-matrix)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

In this lab, I delve into matrix operations and transformations. This repository provides C implementations to create matrices, sort them, and convert sorted vectors into spiral matrices.

## Matrix Manipulation

### Generate Matrix

The `generateMatrix` function generates a random matrix of specified dimensions.

### Create Matrix

The `createMatrix` function allows users to manually input matrix elements or generate a matrix randomly.

### Print Matrix

The `printMatrix` function displays the contents of a matrix.

## Sorting and Transformation

### Bubble Sort

The `bubbleSort` function efficiently sorts an integer array using the bubble sort algorithm.

### Matrix to Vector

The `MatrixToVector` function converts a matrix into a one-dimensional integer array.

### Vector to Spiral Matrix

The `ToSpiral` function converts a sorted integer array back into a spiral matrix.

## Usage

1. **Compile the Code:** Compile the C code using your preferred C compiler.

   ```bash
   gcc -o main.c
   ```

2. **Run the Program:** Execute the program.

   ```bash
   ./a.exe
   ```

3. **Follow On-Screen Prompts:** Enter the number of rows and columns for the matrix, choose to enter the matrix manually or generate it randomly, and provide the matrix elements accordingly.

4. **Review Results:** The program will print the generated or entered matrix, the sorted matrix, and the time taken to execute the program.

## Contributing

Contributions to this repository are welcome! If you have suggestions for improvements or additional features related to matrix manipulation or sorting algorithms, please consider opening a pull request. Your contributions can enhance the learning experience for fellow students.

## License

This project is licensed under the TUM License.

---
