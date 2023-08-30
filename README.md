# Unique Words Counter

This project was undertaken as a home assignment task with the goal of developing a C++ program that accurately counts the number of distinct unique words in a file. The program takes the file's name as an argument and efficiently processes the content to provide the desired output.

## Problem Statement

The program addresses the following requirements:

- **Input**: The program receives a filename as an argument and reads the content of the specified file.
- **Counting Unique Words**: The program calculates the count of distinct unique words in the provided file. For instance, if the file contains the text "a horse and a dog," the program should output "4" (since the word 'a' appears twice but contributes only one distinct occurrence).
- **Character Set**: The input text comprises only lowercase alphabetical characters ('a' to 'z') and space characters in ASCII encoding.
- **Handling Large Inputs**: The program is designed to handle substantial input sizes, even up to 32 GiB.
- **Memory Usage**: The solution assumes that all unique words can fit into memory, allowing the use of a suitable data structure.
- **Utilizing CPU Resources**: The program effectively utilizes all available CPU resources to ensure efficient processing.

## Implementation Details

The project is implemented in C++, utilizing the Linux sys library to access memory mapping and obtain file sizes. While the code prioritizes accurate unique word counting, other areas of the code might not be optimized for elegance or safety. The focus has been on addressing the core problem statement.

## Usage

To run the program, follow these steps:

1. Compile the C++ source code using a C++ compiler (e.g., g++).
2. Execute the compiled program, passing the desired file's name as a command-line argument.

```bash
g++ unique_words_counter.cpp -o unique_words_counter
./unique_words_counter input_file.txt
```

Please note that this solution assumes a basic understanding of C++ programming, command-line usage, and file handling. If you encounter any issues or have questions, refer to relevant documentation or seek assistance from experienced developers or forums.
