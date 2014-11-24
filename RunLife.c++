// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;

	string type, row;
	int n, m;
	
    // -----------------
    // Conway Cell 21x13
    // -----------------

    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */
	cin >> type;
	cin >> n >> m;
	
	Life<ConwayCell> l1 (n, m);
	
	for(int i = 0; i < n; i++)
	{
		cin >> row;
		for(unsigned j = 0; j < row.size(); j++)
		{
			if(row[j] == '*')
			{
				l1.InitializeGrid(i, j);
			}
		}
	}
	

    // -----------------
    // Conway Cell 20x29
    // -----------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */
	cin >> type;
	cin >> n >> m;
	
	Life<ConwayCell> l2 (n, m);
	
	for(int i = 0; i < n; i++)
	{
		cin >> row;
		for(unsigned j = 0; j < row.size(); j++)
		{
			if(row[j] == '*')
			{
				l2.InitializeGrid(i, j);
			}
		}
	}
	
    // ------------------
    // Conway Cell 109x69
    // ------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */
	cin >> type;
	cin >> n >> m;
	
	Life<ConwayCell> l3 (n, m);
	
	for(int i = 0; i < n; i++)
	{
		cin >> row;
		for(unsigned j = 0; j < row.size(); j++)
		{
			if(row[j] == '*')
			{
				l3.InitializeGrid(i, j);
			}
		}
	}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
	cin >> type;
	cin >> n >> m;
	
	Life<FredkinCell> l4 (n, m);
	
	for(int i = 0; i < n; i++)
	{
		cin >> row;
		for(unsigned j = 0; j < row.size(); j++)
		{
			if(row[j] == '0')
			{
				l4.InitializeGrid(i, j);
			}
		}
	}

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
	
	/*
	for(int i = 0; i < n; i++)
	{
		for(unsigned j = 0; j < m; j++)
		{
			if(l4.grid[i][j].IsAlive())
				cout << "0";
			else
				cout << "-";
		}
		cout << endl;
	}
	*/

    return 0;}
