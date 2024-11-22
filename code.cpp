#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;

const int ROWS = 5, COLS = 5, MINES = 5; // 5x5 board with 5 mines

void setBoard(vector<vector<char>> &board)
{
	srand(time(0));
	int placed = 0;
	while (placed < MINES)
	{
		int row = rand() % ROWS;
		int col = rand() % COLS;
		if (board[row][col] != '*')
		{
			board[row][col] = '*';
			placed++;
		}
	}
}

int returnCellcount(vector<vector<char>> &board, int row, int col)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int rowtocheck = row + i;
			int coltocheck = col + j;
			if (rowtocheck >= 0 && rowtocheck < ROWS && coltocheck >= 0 && coltocheck < COLS)
			{
				if (board[rowtocheck][coltocheck] == '*')
				{
					count++;
				}
			}
		}
	}
	return count;
}

void putvalues(vector<vector<char>> &board)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (board[i][j] != '*')
			{
				int count = returnCellcount(board, i, j);
				if (count > 0)
				{
					board[i][j] = '0' + count; // convert count to character
				}
				else
				{
					board[i][j] = '0'; // empty cell
				}
			}
		}
	}
}

void show(vector<vector<char>> &board, vector<vector<bool>> &revealed, vector<vector<bool>> &flagged)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (revealed[i][j])
			{
				cout << board[i][j] << "\t";
			}
			else if (flagged[i][j])
			{
				cout << "F\t";
			}
			else
			{
				cout << "-\t";
			}
		}
		cout << endl
		     << endl;
	}
}

void playGame(vector<vector<char>> &board)
{
	vector<vector<bool>> revealed(ROWS, vector<bool>(COLS, false)); // revealed boolean vector
	vector<vector<bool>> flagged(ROWS, vector<bool>(COLS, false));  // flagged boolean vector

	bool gameOver = false;

	while (!gameOver)
	{
		show(board, revealed, flagged); // current state of the board

		int row, col;
		char action;
		cout << "Enter action (r for reveal, f for flag) followed by row and column (e.g., r 1 1): ";
		cin >> action >> row >> col;

		// convert to 0-based indexes
		row--;
		col--;

		if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
		{
			cout << "Invalid coordinates. Please try again." << endl;
			continue;
		}

		if (action == 'r')
		{
			if (flagged[row][col])
			{
				cout << "This cell is flagged. You must unflag it first to reveal!" << endl;
				continue;
			}

			if (board[row][col] == '*')
			{
				cout << "OOpppssss! You hit a mine!" << endl
				     << "------Game Over!------" << endl;
				revealed[row][col] = true;
				show(board, revealed, flagged);
				gameOver = true;
			}
			else
			{
				revealed[row][col] = true;
			}
		}
		else if (action == 'f')
		{
			if (revealed[row][col])
			{
				cout << "You cannot flag a revealed cell!" << endl;
				continue;
			}

			flagged[row][col] = !flagged[row][col];
		}

		bool win = true;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (board[i][j] != '*' && !revealed[i][j])
				{
					win = false;
					break;
				}
			}
			if (!win)
			{
				break;
			}
		}
		if (win)
		{
			cout << "Congratulations! You WON!" << endl;
			gameOver = true;
		}
	}

	cout << "Well Played! The board was:" << endl;
	vector<vector<bool>> Revealfull(ROWS, vector<bool>(COLS, true));
	show(board, Revealfull, flagged);
}

int main()
{
	vector<vector<char>> board(ROWS, vector<char>(COLS, '-')); // original board will have all dashes
	setBoard(board);
	putvalues(board);
	playGame(board);
	return 0;
}
