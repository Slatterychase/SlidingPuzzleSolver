#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Board {

public:
	vector<vector<int>> board;

	Board();
	Board(vector<vector<int>> replacement);
	~Board();
	
	void setBoard(vector<vector<int>> replacement);
	vector<vector<int>> currentBoard();
	int Manhattan(vector<vector<int>> final);
	vector<int> getMove();
	void move(int direction);
	int getBlankX();
	int getBlankY();
	void PrintPuzzle();
	enum Direction { up, down, rght, lft, none };
	void swapSpace(int x1, int y1, int x2, int y2);
	vector<vector<int>> shuffleBoard(int shuffleCount);
	bool isGoalState(vector<vector<int>> original);
	vector<int> path;
	vector<vector<int>> getCopy();
	int lastMove;


	
};
