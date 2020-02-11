# Hash-Table

Class: Data Structures - Irvine Valley College Fall 2019

Program Specification:

Build a hash table using chaining as the collision resolution technique. Insertions into the hash table will correspond to declarations of variables and values in a program, searches will be requests for the value of a variable. Some variables will be local and have a narrow scope while some variables will be global.

The program will take input from a file, another program written in the omnipotent programming language BORG (Bionicly Omnipotent Resistance Grinders) and generate output from this program.

The BORG language has the following commands (keywords):

1. START-FINISH blocks. Indicating different scopes.
2. COM - Single line comments: Text should be ignored if on the same line
3. VAR varName – Variable Declaration, adds “varName” to the hash table.
4. variable = expression – Assignment statements, ie GEORGE = 122. Find GEORGE in the hash table and assign 122 to it.
5. ++ - increment operator, syntax: VARIABLE ++
6. -- - decrement operator, syntax: VARIABLE --
7. expressions, expressions are limited to unary and binary arithmetic, or variable names
8. supported operators: +  -  /  *  %  ^ (plus, minus, divide, multiple, modulo, exponent)
9. PRINT – syntax PRINT expression. If the expression is a variable, and this variable is not in scope, then an error message indicating unknown variable x at line number y. The value printed if there is a variable in scope should be the variable with the closest scope.
10. Errors – other than the print statements, our interpreter will not be responsible for detecting errors, syntax errors should be disregarded if encountered, assume that the source file is correct.
Our hash function: sum the ordinal values of the characters of the variable multiplied by their position in the string (1-indexing), then taking the modulo by TABLESIZE.

The variable ABC = (65 * 1 + 66 * 2 + 67 * 3) % TABLESIZE
All tokens are separated by one space or a new line.

Output: https://docs.google.com/document/d/1EMKw-JneefaExQOzhGhaa0sPwU5FE1HPJSVjohFTj_U/edit?usp=sharing
