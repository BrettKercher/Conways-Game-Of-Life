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
	
	//Initialize Grid
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
	
	//Print Initial Grid
	cout << l1;
	
	//Simulate 12 Generations
	for(int i = 1; i <= 12; i++)
	{
		l1.NextGeneration();
		cout << l1;
	}
	
	cout << endl;
	

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
	
	//Print Initial Grid
	cout << l2;
	
	//Simulate 28 Generations
	for(int i = 1; i <= 28; i++)
	{
		l2.NextGeneration();
		if(i%4 == 0)
			cout << l2;
	}
	
	cout << endl;
	
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
	
	//Print Initial Grid
	cout << l3;
	
	//Simulate 283 Generations
	for(int i = 1; i <= 283; i++)
	{
		l3.NextGeneration();
		if(i < 10)
			cout << l3;
	}
	
	//Print the 283rd generation
	cout << l3;
	
	//Simulate 40 Generations
	for(int i = 0; i < 40; i++)
	{
		l3.NextGeneration();
	}
	
	//Print the 323rd generation
	cout << l3;
	
	
	//Simulate 2177 Generations
	for(int i = 0; i < 2177; i++)
	{
		l3.NextGeneration();
	}
	
	//Print the 2500th generation
	cout << l3;
	
	cout << endl;

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
	
	//Print Initial Grid
	cout << l4;
	
	//Simulate 5 Generations
	for(int i = 1; i <= 5; i++)
	{
		l4.NextGeneration();
		cout << l4;
	}
	
	cout << endl;

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
	
	cin >> type;
	cin >> n >> m;
	
	Life<Cell> l5 (n, m);
	
 	for(int i = 0; i < n; i++)
 	{
 		cin >> row;
 		for(unsigned j = 0; j < row.size(); j++)
 		{
 			if(row[j] == '0')
 			{
 				l5.InitializeGrid(i, j, FREDKIN);
 			}
 			else if(row[j] == '*')
			{
				l5.InitializeGrid(i, j, CONWAY);
			}
 		}
 	}
 	
 	//Print Initial Grid
	cout << l5;
	
	//Simulate 5 Generations
	for(int i = 1; i <= 5; i++)
	{
		l5.NextGeneration();
		cout << l5;
	}

    return 0;}
