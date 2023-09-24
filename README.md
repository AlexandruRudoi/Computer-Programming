# Laboratory work #2

This repository contains implementations of four popular sorting algorithms in C: Bubble Sort, Selection Sort, Insertion Sort, and Quick Sort. The code also includes a timer to measure the execution time of each algorithm.

## Table of Contents

- [Introduction](#introduction)
- [Sorting Algorithms](#sorting-algorithms)
  - [Bubble Sort](#bubble-sort)
  - [Selection Sort](#selection-sort)
  - [Insertion Sort](#insertion-sort)
  - [Quick Sort](#quick-sort)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Sorting is a fundamental operation in computer science and is used in various applications. This repository provides C implementations of four sorting algorithms:

1. **Bubble Sort**: A simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

2. **Selection Sort**: A simple in-place comparison-based sorting algorithm. It divides the input list into two parts: a sorted sub-list and an unsorted sub-list.

3. **Insertion Sort**: A simple comparison-based sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

4. **Quick Sort**: An efficient, comparison-based sorting algorithm that uses a divide-and-conquer approach to sort an array or list. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot.

## Sorting Algorithms 

### Bubble Sort

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.

### Selection Sort

Selection Sort is an in-place comparison-based sorting algorithm. It divides the input list into two parts: a sorted sub-list and an unsorted sub-list. It repeatedly selects the minimum element from the unsorted sub-list and moves it to the beginning of the sorted sub-list.

### Insertion Sort

Insertion Sort is a simple comparison-based sorting algorithm that builds the final sorted array one item at a time. It iterates through the input list, takes one element at a time, and places it in its correct position within the sorted part of the list.

### Quick Sort

Quick Sort is an efficient, comparison-based sorting algorithm that uses a divide-and-conquer approach. It selects a 'pivot' element from the array and partitions the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.

## Usage

To use the sorting algorithms implemented in this repository, follow these steps:

1. Clone the repository to your local machine:

   ```bash
   git clone -b Lab-2 https://github.com/AlexandruRudoi/Computer-Programming.git
   cd Computer-Programming
   ```

2. Compile the C code:

   ```bash
   gcc -o main.c
   ```

3. Run the program:

   ```bash
   ./a.exe
   ```

4. Follow the on-screen prompts to enter the number of elements and the elements themselves. If you need random numbers for testing purposes, you can use online tools like [OnlineTools - Generate Random Numbers](https://onlinetools.com/number/generate-random-numbers) to generate a list of random numbers.

5. The program will display the sorted array using each of the four sorting algorithms and measure the execution time.

## Contributing

Contributions to this repository are welcome! If you have any improvements or additional sorting algorithms to add, please open a pull request. Make sure to follow the existing code style and add appropriate documentation.

## License

This project is licensed under the TUM License.
