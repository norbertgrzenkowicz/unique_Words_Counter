#### Unique words Counter

This project was made as home assignment task:

Please submit the complete C++ source code for a program that counts the number of distinct unique words in a file whose name is passed as an argument to a program. For example, given the file content "a horse and a dog" the program must output "4" (the word 'a' appears twice but only accounts for one distinct unique occurrence). The input text is guaranteed to contain only 'a'..'z' and space characters in ASCII encoding. The program should be able to handle large inputs (e.g. 32 GiB). You can assume that all unique words fit into memory when using the data structure of your choice.
The solution must utilize all available CPU resources.

Did it in plain C++ in pair with sys linux library to access to memory mapping and file's sizes.

Disclaimer:
Code might be not elegant or safe in other areas than unique words counting just to focus more on actual problem.
