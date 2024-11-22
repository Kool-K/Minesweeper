Minesweeper Game
A console-based implementation of the classic Minesweeper game in C++. 
The game allows users to play on a 5x5 grid with 5 randomly placed mines.
Objective : Reveal all cells that do not contain mines without triggering any mines. Players can also flag cells that they suspect contain mines.

Features
Randomly Placed Mines: The game randomly places 5 mines on the grid.
Cell Reveal: Players can reveal cells to uncover numbers or mines.
Flagging: Players can flag cells to mark them as suspected mines.
Win Condition: The player wins by revealing all non-mine cells.
Game Over: The game ends if a mine is revealed.
Game Actions
r: Reveal a cell (e.g., r 1 1 to reveal the cell at row 1, column 1).
f: Flag a cell (e.g., f 1 1 to flag the cell at row 1, column 1).
Rows and Columns: Coordinates are 1-based (i.e., row 1, column 1 is the top-left corner of the grid).
Requirements
C++ Compiler (e.g., GCC, Clang)
Basic understanding of C++ programming and working with 2D arrays.
