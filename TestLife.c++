// --------------------------------
// TestLife.c++
// Brett M. Kercher
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Life.h"

// -----------
// TestLife
// -----------

// ----
//  Test Constructor
// ----

TEST(Life, life_constructor_1) 
{
	Life<ConwayCell> x(12,15);
	
	for(int i = 0; i <12; i++)
		for(int j = 0; j < 15; j++)
			ASSERT_EQ(x.grid[i][j].IsAlive(), false);
}

TEST(Life, life_constructor_2) 
{
	Life<FredkinCell> x(12,15);
	
	for(int i = 0; i <12; i++)
		for(int j = 0; j < 15; j++)
			ASSERT_EQ(x.grid[i][j].IsAlive(), false);
}

// ----
//  Test NotifyNeighbors Function
// ----

TEST(Life, life_notify_1) 
{
	Life<ConwayCell> x(10,10);
	
	x.InitializeGrid(1,1);
	
	ASSERT_EQ(x.grid[1][1].IsAlive(), true);
	
	ASSERT_EQ(0, x.grid[0][0].neighbors);
	ASSERT_EQ(0, x.grid[1][0].neighbors);
	ASSERT_EQ(0, x.grid[0][1].neighbors);
	ASSERT_EQ(0, x.grid[0][2].neighbors);
	ASSERT_EQ(0, x.grid[2][0].neighbors);
	ASSERT_EQ(0, x.grid[1][2].neighbors);
	ASSERT_EQ(0, x.grid[2][1].neighbors);
	ASSERT_EQ(0, x.grid[2][2].neighbors);
	
	x.NotifyNeighbors(1, 1, true);
	
	ASSERT_EQ(0, x.grid[1][1].neighbors);
	ASSERT_EQ(1, x.grid[0][0].neighbors);
	ASSERT_EQ(1, x.grid[1][0].neighbors);
	ASSERT_EQ(1, x.grid[0][1].neighbors);
	ASSERT_EQ(1, x.grid[0][2].neighbors);
	ASSERT_EQ(1, x.grid[2][0].neighbors);
	ASSERT_EQ(1, x.grid[1][2].neighbors);
	ASSERT_EQ(1, x.grid[2][1].neighbors);
	ASSERT_EQ(1, x.grid[2][2].neighbors);
}

TEST(Life, life_notify_2) 
{
	Life<ConwayCell> x(10,10);
	
	x.InitializeGrid(0,0);
	
	ASSERT_EQ(x.grid[0][0].IsAlive(), true);
	
	x.NotifyNeighbors(0, 0, true);
	
	ASSERT_EQ(1, x.grid[0][1].neighbors);
	ASSERT_EQ(1, x.grid[1][0].neighbors);
	ASSERT_EQ(1, x.grid[1][1].neighbors);
}

TEST(Life, life_notify_3) 
{
	Life<ConwayCell> x(10,10);
	
	x.InitializeGrid(0,0);
	x.InitializeGrid(1,1);
	
	ASSERT_EQ(x.grid[0][0].IsAlive(), true);
	ASSERT_EQ(x.grid[1][1].IsAlive(), true);

	x.NotifyNeighbors(1, 1, true);
	
	ASSERT_EQ(1, x.grid[0][0].neighbors);
	ASSERT_EQ(1, x.grid[1][0].neighbors);
	ASSERT_EQ(1, x.grid[0][1].neighbors);
	ASSERT_EQ(1, x.grid[0][2].neighbors);
	ASSERT_EQ(1, x.grid[2][0].neighbors);
	ASSERT_EQ(1, x.grid[1][2].neighbors);
	ASSERT_EQ(1, x.grid[2][1].neighbors);
	ASSERT_EQ(1, x.grid[2][2].neighbors);
	
	x.NotifyNeighbors(0, 0, true);
	
	ASSERT_EQ(2, x.grid[0][1].neighbors);
	ASSERT_EQ(2, x.grid[1][0].neighbors);
	ASSERT_EQ(1, x.grid[1][1].neighbors);
}

TEST(Life, life_notify_4) 
{
	Life<ConwayCell> x(5,10);
	
	x.InitializeGrid(4,9);
	
	ASSERT_EQ(x.grid[4][9].IsAlive(), true);

	x.NotifyNeighbors(4, 9, true);
	
	ASSERT_EQ(1, x.grid[4][8].neighbors);
	ASSERT_EQ(1, x.grid[3][8].neighbors);
	ASSERT_EQ(1, x.grid[3][9].neighbors);
}

TEST(Life, life_notify_5) 
{
	Life<FredkinCell> x(5,10);
	
	x.InitializeGrid(4,9);
	
	ASSERT_EQ(x.grid[4][9].IsAlive(), true);

	x.NotifyNeighbors(4, 9, false);
	
	ASSERT_EQ(0, x.grid[4][9].neighbors);
	ASSERT_EQ(1, x.grid[4][8].neighbors);
	ASSERT_EQ(0, x.grid[3][8].neighbors);
	ASSERT_EQ(1, x.grid[3][9].neighbors);
}

TEST(Life, life_notify_6) 
{
	Life<FredkinCell> x(5,10);
	
	x.InitializeGrid(4,9);
	x.InitializeGrid(3,9);
	
	ASSERT_EQ(x.grid[4][9].IsAlive(), true);
	ASSERT_EQ(x.grid[3][9].IsAlive(), true);

	x.NotifyNeighbors(4, 9, false);
	
	ASSERT_EQ(0, x.grid[4][9].neighbors);
	ASSERT_EQ(1, x.grid[4][8].neighbors);
	ASSERT_EQ(0, x.grid[3][8].neighbors);
	ASSERT_EQ(1, x.grid[3][9].neighbors);
	
	x.NotifyNeighbors(3, 9, false);
	
	ASSERT_EQ(1, x.grid[3][9].neighbors);
	ASSERT_EQ(1, x.grid[4][9].neighbors);
	ASSERT_EQ(1, x.grid[3][8].neighbors);
	ASSERT_EQ(1, x.grid[2][9].neighbors);
}

TEST(Life, life_notify_7) 
{
	Life<FredkinCell> x(5,10);
	
	x.InitializeGrid(0,0);
	x.InitializeGrid(1,1);
	
	ASSERT_EQ(x.grid[0][0].IsAlive(), true);
	ASSERT_EQ(x.grid[1][1].IsAlive(), true);

	x.NotifyNeighbors(0, 0, false);
	
	ASSERT_EQ(0, x.grid[0][0].neighbors);
	ASSERT_EQ(1, x.grid[0][1].neighbors);
	ASSERT_EQ(0, x.grid[1][1].neighbors);
	ASSERT_EQ(1, x.grid[1][0].neighbors);
	
	x.NotifyNeighbors(1, 1, false);
	
	ASSERT_EQ(0, x.grid[0][0].neighbors);
	ASSERT_EQ(2, x.grid[0][1].neighbors);
	ASSERT_EQ(0, x.grid[1][1].neighbors);
	ASSERT_EQ(2, x.grid[1][0].neighbors);
}

// ----
//  Test InitializeGrid Function
// ----

TEST(Life, life_init_1) 
{
	Life<ConwayCell> x(12,15);
	
	x.InitializeGrid(0,0);
	x.InitializeGrid(1,1);
	
	ASSERT_EQ(x.grid[0][0].IsAlive(), true);
	ASSERT_EQ(x.grid[1][1].IsAlive(), true);
}

TEST(Life, life_init_2) 
{
	Life<FredkinCell> x(12,15);
	
	x.InitializeGrid(0,0);
	x.InitializeGrid(11,14);
	
	ASSERT_EQ(x.grid[0][0].IsAlive(), true);
	ASSERT_EQ(x.grid[11][14].IsAlive(), true);
}

// ----
//  Test InitializeGrid Function
// ----

TEST(Life, life_next_gen_1) 
{
	Life<ConwayCell> x(5,5);
	
	x.InitializeGrid(2,1);
	x.InitializeGrid(2,2);
	x.InitializeGrid(2,3);
	
	x.NextGeneration();
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if( (i == 2 && j == 2) || (i == 3 && j == 2) || (i == 1 && j == 2) )
				ASSERT_EQ(x.grid[i][j].IsAlive(), true);
			else
				ASSERT_EQ(x.grid[i][j].IsAlive(), false);
		}
	}
}

TEST(Life, life_next_gen_2) 
{
	Life<ConwayCell> x(19,5);
	
	x.InitializeGrid(2,1);
	x.InitializeGrid(2,2);
	x.InitializeGrid(2,3);
	
	x.NextGeneration();
	
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if( (i == 2 && j == 2) || (i == 3 && j == 2) || (i == 1 && j == 2) )
				ASSERT_EQ(x.grid[i][j].IsAlive(), true);
			else
				ASSERT_EQ(x.grid[i][j].IsAlive(), false);
		}
	}
}

TEST(Life, life_next_gen_3) 
{
	Life<FredkinCell> x(19,5);
	
	x.InitializeGrid(2,1);
	x.InitializeGrid(2,2);
	x.InitializeGrid(2,3);
	
	x.NextGeneration();
	
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if( (i == 1 && j == 1) || (i == 1 && j == 2) || (i == 1 && j == 3) ||
					(i == 3 && j == 1) || (i == 3 && j == 2) || (i == 3 && j == 3) ||
						(i == 2 && j == 0) || (i == 2 && j == 1) || (i == 2 && j == 3) || (i == 2 && j == 4))
				ASSERT_EQ(x.grid[i][j].IsAlive(), true);
			else
			{
				ASSERT_EQ(x.grid[i][j].IsAlive(), false);
			}
		}
	}
}

// -----------
// Test Conway
// -----------

// ----
//  Test Constructor
// ----

TEST(Life, conway_constructor_1) 
{
	ConwayCell cc;
	
	ASSERT_EQ(cc.alive, false);
	ASSERT_EQ(cc.type, CONWAY);
	ASSERT_EQ(cc.neighbors, 0);
}

// ----
//  Test Evolve
// ----

TEST(Life, conway_evolve_1) 
{
	ConwayCell cc;
	
	cc.alive = true;
	cc.neighbors = 1;
	cc.type = CONWAY;
	
	cc.Evolve();
	
	ASSERT_EQ(cc.alive, false);
}

TEST(Life, conway_evolve_2) 
{
	ConwayCell cc;
	
	cc.alive = true;
	cc.neighbors = 2;
	cc.type = CONWAY;
	
	cc.Evolve();
	
	ASSERT_EQ(cc.alive, true);
}

TEST(Life, conway_evolve_3) 
{
	ConwayCell cc;
	
	cc.alive = false;
	cc.neighbors = 3;
	cc.type = CONWAY;
	
	cc.Evolve();
	
	ASSERT_EQ(cc.alive, true);
}

TEST(Life, conway_evolve_4) 
{
	ConwayCell cc;
	
	cc.alive = false;
	cc.neighbors = 1;
	cc.type = CONWAY;
	
	cc.Evolve();
	
	ASSERT_EQ(cc.alive, false);
}

TEST(Life, conway_evolve_5) 
{
	ConwayCell cc;
	
	cc.alive = true;
	cc.neighbors = 4;
	cc.type = CONWAY;
	
	cc.Evolve();
	
	ASSERT_EQ(cc.alive, false);
}

// -----------
// Test Fredkin
// -----------

// ----
//  Test Constructor
// ----

TEST(Life, fredkin_constructor_1) 
{
	FredkinCell fc;
	
	ASSERT_EQ(fc.alive, false);
	ASSERT_EQ(fc.type, FREDKIN);
	ASSERT_EQ(fc.neighbors, 0);
	ASSERT_EQ(fc.age, 0);
}

// ----
//  Test Evolve
// ----

TEST(Life, fredkin_evolve_1) 
{
	FredkinCell fc;
	
	fc.alive = true;
	fc.neighbors = 0;
	fc.type = FREDKIN;
	
	fc.Evolve();
	
	ASSERT_EQ(fc.alive, false);
}

TEST(Life, fredkin_evolve_2) 
{
	FredkinCell fc;
	
	fc.alive = true;
	fc.neighbors = 2;
	fc.type = FREDKIN;
	
	fc.Evolve();
	
	ASSERT_EQ(fc.alive, false);
}

TEST(Life, fredkin_evolve_3) 
{
	FredkinCell fc;
	
	fc.alive = true;
	fc.neighbors = 4;
	fc.type = FREDKIN;
	
	fc.Evolve();
	
	ASSERT_EQ(fc.alive, false);
}

TEST(Life, fredkin_evolve_4) 
{
	FredkinCell fc;
	
	fc.alive = true;
	fc.neighbors = 1;
	fc.type = FREDKIN;
	
	fc.Evolve();
	
	ASSERT_EQ(fc.alive, true);
}

TEST(Life, fredkin_evolve_5) 
{
	FredkinCell fc;
	
	fc.alive = false;
	fc.neighbors = 1;
	fc.type = FREDKIN;
	
	fc.Evolve();
	
	ASSERT_EQ(fc.alive, true);
}

TEST(Life, fredkin_evolve_6) 
{
	FredkinCell fc;
	
	fc.alive = false;
	fc.neighbors = 2;
	fc.type = FREDKIN;
	
	fc.Evolve();
	
	ASSERT_EQ(fc.alive, false);
}

