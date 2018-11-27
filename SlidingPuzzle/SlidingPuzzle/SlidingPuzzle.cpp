// Charles Slattery
//Main File used for calling others and asking for user input.
//References:
//A*: https://picoledelimao.github.io/blog/2015/12/06/solving-the-sliding-puzzle/
//Hill Climbing: http://journeyofalazyprogrammer.blogspot.com/2013/10/8-puzzle-problem-solution-using.html?view=sidebar

//Some puzzles will loop, or will be found to have no better manhattan going forward, and I am not sure if that 
//is due to the puzzle being unsolvable or not, which I think is due to the lack of checking for previously used states.

//Bonus: I didn't do any of the conventional bonus parts lsited, however I believe there may be some points in allowing the user to select the amount of shuffles they do.

#include "pch.h"

#include <iostream>
#include <queue>
#include <time.h>
#include "Board.h"
#include "State.h"
#include <string>
using namespace std;

int main()
{
	
	Board board;
	Board correctBoard;
	
	srand(time(NULL));
	string input = "";
	cout << "Starting Puzzle" << endl;
	cout << "_______________________________<<" << endl;
	board.PrintPuzzle();
	while (input != "quit") {
		cout << "Enter command, shuffle to shuffle the puzzle, hill to solve by hill climbing, and a* to solve by a star, press quit to close!" << endl;
		cin >> input;
		//shuffles the board
		if (input == "shuffle") {
			int shuffles = 0;
			cout << "Enter number of shuffles" << endl;
			cin >> shuffles;
			board.shuffleBoard(shuffles);
			cout << "Shuffled Board" << endl;
			board.PrintPuzzle();
		}
		if (input == "a*") {
			//gets starting board
			State starting(board, correctBoard);
			//stores it in main
			board = starting.current.getCopy();
			//gets path of the astar function
			vector<int> path = starting.aStar();
			cout << "End result" << endl;
			
		}
		if (input == "hill") {
			//creates first state
			State starting(board, correctBoard);
			//copies the starting state to the board
			board = starting.current.getCopy();
			//gets the path the original must move in order to hill climb
			vector<int> path = starting.hillClimbing();
			//for loop to move the puzzle according to the returned vector
			for (int x = 0; x < path.size(); x++) {
				
				board.move(path[x]);
			}
			board.PrintPuzzle();
		}

		
		

		
		

	}
	

	

	
	
	
	
	
	
	
}


