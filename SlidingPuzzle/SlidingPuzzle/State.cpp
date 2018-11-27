//Charles Slattery
//Function for handling different states, used to solve the puzzles. Has functions for solving through a* as well as by hill climbing.
#include "pch.h"
#include "State.h"


State::State(Board crrnt, Board gl)
{
	current = crrnt;
	goal = gl;
	
}


State::~State()
{

}

vector<int> State::aStar()
{
	//create a priority queue to work as a minheap
	priority_queue<State> states;
	//creates the starting state
	State initial(current, goal);
	//adds it to the vector of states
	states.push(initial);
	//check that while states remain possible
	while (states.size() > 0) {
		//find the top state
		State state = states.top();
		
	
		//remove it from the states
		states.pop();
		//if the manhattan is 0, its the goal so return the path
		if (state.current.Manhattan(goal.currentBoard()) == 0) {
			//print the puzzle of that state
			cout << "Solved Puzzle" << endl;
			state.current.PrintPuzzle();
			return path;
		}
		//otherwise create children states, and push them to the states list to be evaluated
		vector<State> children = state.visit(state.current);
		for (int i = 0; i < children.size(); i++) {
			State child = children[i];
			states.push(child);
		}
	}
	
}

vector<int> State::hillClimbing() {
	Board temp = current;
	Board closest = current;
	int direction; 
	vector<int> validMoves = current.getMove(); 
	for (int x = 0; x < validMoves.size(); x++) {													
		temp.move(validMoves[x]);	
		//checks if there is lower manhattan then currently being held
		if (temp.Manhattan(goal.getCopy()) < closest.Manhattan(goal.getCopy())) {	
			closest = temp;	
			direction = validMoves[x];
		}
		temp = current; 
	}
	//if Manhattan is 0, then it must be the goal state,
	if (closest.Manhattan(goal.getCopy()) == 0) { 
		cout << "Answer Found" << endl;;
		cout << "-------------------------" << endl;

		path.push_back(direction);	
		return path;				
	}
	//if theres no lower manhattan, no solution exists, could be due to bad shuffle
	if (closest.Manhattan(goal.getCopy()) >= current.Manhattan(goal.getCopy())) { // if the current state has no moves that have a lower manhattan, returns path to that point.
		cout << "No solution" << endl;
		return path;
	}
	//adds decided direction
	path.push_back(direction);
	//creates new state, with whats deemed closest
	State bestChild(closest, goal);
	//recursively calls the hill climb function using the best child
	vector<int> newPath = bestChild.hillClimbing();
	for (int i = 0; i < newPath.size(); i++) {
		path.push_back(newPath[i]);
	}
	return path;
}

vector<State> State::visit(Board crrnt) {
	vector<State> children;
	vector<int> possibleMoves = crrnt.getMove();
	//loops through possible moves, and creates new children based on possible moves
	for (int x = 0; x < static_cast<int>(possibleMoves.size()); x++) {
		int move = possibleMoves[x];
		State newState(crrnt, goal);
		newState.current.move(move);
		newState.path.push_back(move);
		children.push_back(newState);
	}
	return children;
}
//defined operations for checking two states equality and if one is less than the other.
bool operator<(State a, State b)
{
	return a.current.Manhattan(a.goal.currentBoard()) + a.path.size() > b.current.Manhattan(b.goal.currentBoard()) + b.path.size();
}

bool operator==(State a, State b)
{
	return a.current.Manhattan(a.goal.currentBoard()) == b.current.Manhattan(b.goal.currentBoard());
}


