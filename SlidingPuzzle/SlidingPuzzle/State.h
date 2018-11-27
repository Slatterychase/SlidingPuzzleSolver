#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Board.h"
#include <time.h>

using namespace std;
class State
{
public:
	State(Board crrnt, Board gl);
	~State();
	Board current;
	Board goal;
	vector<int> path;
	int manhattan = 0;
	vector<int> aStar();
	vector<State> visit(Board current);
	vector<int> hillClimbing();
	
	friend bool operator< (State a, State b);
	friend bool operator== (State a, State b);
};

