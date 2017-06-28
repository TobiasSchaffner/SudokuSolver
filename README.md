# Sudoku Solver

![Alt text](images/sudoku.jpg?raw=true "Sudoku")


## Content

We implemented a fast Sudoku solver based on a recursive bruteforce. Main feature is a smart picking algorithm for the
next field to process based on the information the board provides for the empty fields. This was done in a very
efficient way by holding bitmasks to avoid to much memory overhead.

The environment variable "SUDOKU_CONF" has to be set to the path of the conf dir for the program to find csv sudoku
files.

1. Recursive solving

As can be seen in the solver.cpp we use a recursive algorithm to iterate over the empty fields and try to find solutions
for them. The solve method will try to fill a field and call itself until either there is no possible solution for the
field or all fields are filled. First case will lead to reversing all the moves to the last point where a decision
between multiple options was made. In this case it will try the next option for that point. Second case will return with
a solved board.

2. Next field picking

Each row/column/segment of the Sudoku holds a Bitmask of length nine. The numbers 1-9 set in the row/column/segment will
be a set bit in the bitmask from right to left (Thanks to Confix for the idea of using bitmasks). This leads us to the
situation that we can determine the number of different numbers that have impact on a field by a simple OR operation on
the bitmasks of row, column and segment of the field. Additionaly we can determine if a number can be set in a field by
the same OR operation and checking if the bit is set.

3. Boards provided by csv-files

It is possible to add boards in a comma seperated file format to the conf dir. The dialog will ask if you want to
solve a board from file. Your file added to that directory will be listet.

4. Generator

For testing purposes we implemented a generator for random sudoku boards. To generate a random board we decided to seed
a board, then solve it and at last remove as many numbers as wanted based on the difficulty. When seeding a board a
common approach is to fill the first row with the numbers 1 to 9 and mix them up. That only leeds to 9! different solved
boards as our solver is deterministic and therefore will always create the same output for the same input. We decided to
fill the first line and the first column of the board. When doing so one has to care about not adding the numbers of the
first segment that are already set by the row in that segment again. One approach could be just to add them at the end
of the column which would not lead to a all possible combinations. We decided to hold two pointers: One at the first
and one at the third position (behind the segment). As long as the first pointer does not point to a position behind the
segment numbers that are not already in the segment will be set at first pointer position while moving the pointer one
to the right. In all other cases the Number will be set to the second pointer while moving the pointer one to the right.

### Docs
[Doxygen Documentation](https://algdat.github.io/blatt-2-sudoku07-1/html)
