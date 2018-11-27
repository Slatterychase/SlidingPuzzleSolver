//Charles Slattery
//File containing all functions and information for an individual board.
#include "pch.h"
#include "Board.h"

Board::Board() {
	for (int x = 0; x < 4; x++) {
		vector<int> row;
		for (int y = 0; y < 4; y++) {
			
			if (x == 3 && y == 3) {
				row.push_back(0);
			}
			else {
				row.push_back(4 * x + y + 1);
			}
		}
		board.push_back(row);
	}

}

Board::Board(vector<vector<int>> replacement) {

	for (int x = 0; x < 4; x++) {
		vector<int> row;
		for (int y = 0; y < 4; y++) {
			row.push_back(replacement[x][y]);
		}
		board.push_back(row);
}
}
Board::~Board() {

}
//sets the board equal to another
void Board::setBoard(vector<vector<int>> replacement) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			board[x][y] = replacement[x][y];
		}
	}
}
//returns board
vector<vector<int>> Board::currentBoard() {
	return board;
}
//helper function to find x index of blank pace
int Board::getBlankX() {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {

			if (board[x][y] == 0) {
				return x;
			}
		}

	}
}
//helper function to get the blank spaces y value
int Board::getBlankY() {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {

			if (board[x][y] == 0) {
				return y;
				
			}
		}

	}
}
//returns a copy of the current board, and any paths associated with it
vector<vector<int>> Board::getCopy() {
	Board temp;
	vector<vector<int>> newPuzzle = temp.currentBoard();
	for (int x = 0; x < 4; x++) {
		
		for (int y = 0; y < 4; y++) {
			newPuzzle[x][y] = board[x][y];
		}
	}
	for (int z = 0; z < path.size(); z++) {
		temp.path.push_back(path[z]);
	}
	return newPuzzle;
}
//checks for availible moves
vector<int> Board::getMove() {
	int blankX = getBlankX();
	int blankY = getBlankY();
	vector<int> possibleMoves;
	if (blankY !=0) {

		 possibleMoves.push_back(down);
	}
	if (blankY != 3 ) {
		possibleMoves.push_back(up);
	}
	if (blankX != 3) {
		possibleMoves.push_back(rght);
	}
	if (blankX != 0) {
		possibleMoves.push_back(lft);
	}
	return possibleMoves;
}
//takes a direction and moves based on the enum value passed in
void Board::move(int direction)
{
	
	int line = getBlankX();
	int column = getBlankY();
	if (direction == lft) {
		swapSpace(line, column, line-1, column);
	}
	else if (direction == rght) {
		swapSpace(line, column, line+1, column );
	}
	else if (direction == up) {
		swapSpace(line, column, line, column+1);
	}
	else if (direction == down) {
		swapSpace(line, column, line, column-1);
	}
	
		
	
}
//loops through the board and prints values
void Board::PrintPuzzle() {
	
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {

			cout << board[x][y];
		}
		cout << endl;

	}
	cout << endl;
}
//shuffles board x amount of times, by find availible moves from the current position, then randomly selecting one and moving the piece
vector<vector<int>> Board::shuffleBoard(int shuffleCount)
{
	
	for (int x = 0; x < shuffleCount; x++) {

		vector<int> possible = getMove();
		int possibleSize = possible.size();
	
		int final = rand() % possibleSize;
		
		
		move(possible[final]);
		
	}
	return board;
}
//loops through the current board, in comparison to the correct board, and if they are completely equal return true, otherwise return false
bool Board::isGoalState(vector<vector<int>> original)
{
	
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (currentBoard()[x][y] != original[x][y]) {
				return false;
			}
		}

	}
	return true;
}
//swaps two spaces
void Board::swapSpace(int x1, int y1, int x2, int y2)
{
	//stores first space in a temporary int value
		int tempPuzzle = board[x1][y1];
		//sets first one equal to second
		board[x1][y1] = board[x2][y2];
		//sets second equal to the temporary stored value
		board[x2][y2] = tempPuzzle;
}
//manattan distance equation, loops through both the correct and current boards, then finds manhattan using the distances from correct position. 
int Board::Manhattan(vector<vector<int>> correctPuzzle) {
	int manhattan = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] > 0) { 
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 4; l++) {
						if (correctPuzzle[k][l] == board[i][j]) {
							manhattan = manhattan + (abs(i - k) + abs(j - l)); 
						}
					}
				}
			}
		}
	}
	return manhattan;
}
