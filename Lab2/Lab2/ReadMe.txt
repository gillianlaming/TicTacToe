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

Extra Credit:
- I ran out of time to complete the extra credit, but I made a fair start on it. 

My design was this:
- iterate through every element being printed out.
- for each element, check to see how many neighbors it had.
- i did this by calculating the indexes of each neighbor. I commended in my code, so you can see my logic there.
- i checked to see if the neighbor existed to see if it was in range of board size, and then if it was, I 
checked to see if the color existed.
- If the color existed, this means that it is contained on the board. 
- I then pushed this element onto a vector of game_pieces
- At first, I was getting a lot of elements with color 'noColor', and I realized this was because I pushed back a lot of 
empty pieces at another point in the lab.
- I then (tried) to print every neighbor by iterating through the vector of game_pieces that I created

The function isn't working properly (but I ran out of time to fix it). I think the problem could lie in a few places.
If I had more time, I would debug by:
1. Looking at the indicies. A problem could have been encountered when I went to calculate the indexes of the neighbors
(particularily the diagonal neighbors)
2. defining/storing variables. I need to recreate a lot of different elements every time the for loop is run, so improper
declaration of variables also could have contributed to this problem.
3. Iterating through the elements. Another potential reason why the function isn't working properly.

Please see my function printInfo (found in GameBoard.cpp) for detailed comments. Thank you!!