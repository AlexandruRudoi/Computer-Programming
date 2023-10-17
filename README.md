# Laboratory work #4

This is a simple text editor implemented in C. The text editor provides basic text manipulation functions, such as entering text, printing the buffer, searching for a word, replacing a word, deleting the buffer, saving text to a file, and loading text from a file. It also includes a TRY-CATCH mechanism for handling exceptions.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Exception Handling](#exception-handling)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This text editor is a command-line tool that allows you to work with text, perform various operations on the text buffer, and save or load text from a file. It also includes a basic exception handling mechanism for robust operation.

## Features

### 1. Print Buffer

Prints the content of the text buffer if it is not empty.

### 2. Enter Text

Allows you to enter text into the text buffer interactively.

### 3. Search for a Word

Searches for a specific word in the text buffer and reports the number of occurrences.

### 4. Replace a Word

Replaces a specific word in the text buffer with another word.

### 5. Delete Buffer

Deletes the entire text buffer.

### 6. Save to File

Saves the content of the text buffer to a file named "text.txt."

### 7. Load from File

Loads text from a file named "text.txt" into the text buffer.

### 8. Exit

Exits the text editor.

## Installation

No special installation is required for this text editor. You can compile and run it using a C compiler. The provided source code should work on most systems.

## Usage

1. **Compile the Code:** Compile the C code using your preferred C compiler.

   ```bash
   gcc -o main.c
   ```

2. **Run the Program:** Execute the program.

   ```bash
   ./a.out
   ```

3. **Use the Menu:** Follow the on-screen menu to select and perform text manipulation operations.

## Exception Handling

This text editor includes a basic TRY-CATCH mechanism for handling exceptions. For example, when saving the buffer to a file, it checks if the buffer is empty and throws an exception if it is. The TRY-CATCH mechanism ensures that the program handles exceptions gracefully.

## Contributing

Contributions to this text editor are welcome! If you have suggestions for improvements or additional features, please consider opening a pull request. Your contributions can enhance the functionality and user experience of the text editor.

## License

This project is licensed under the TUM License.
