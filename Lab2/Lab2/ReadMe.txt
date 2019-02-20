Gillian Laming, Lab 2

Errors encountered over the course of the lab:
- missing type specifier - int assumed
- identifier not found error
- I got a couple infinite loops. It was caused by the break in my print board function
being called at the wrong time.

Test cases ran:
- no input file -> returned error message
- bad input file -> returned error message
- too many arguments -> returned error message
- added blank lines to file -> printed correct board (which means it handled the cases properly)
- added tabs, blank space to file -> printed correct board
- added poorly formatted line to gomoku.txt: "pink stone Q 6 6". It properly ignored it (invalid color), and 
printed all of the other lines correctly.