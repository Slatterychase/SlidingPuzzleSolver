// Charles Slattery
//Main File used for calling others and asking for user input.




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
		cout << "Enter command, shuffle to shuffle the puzzle, hill to solve by hill climbing, and a* to solve by a star, quit to close!" << endl;
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


