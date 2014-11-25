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

TEST(Life, life_constructor_3) 
{
	Life<Cell> x(12,15);
	
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
//  Test GetPopulation Function
// ----

TEST(Life, life_pop_1)
{
	Life<ConwayCell> x(3,10);
	
	x.InitializeGrid(0,0);
	x.InitializeGrid(1,1);
	x.InitializeGrid(0,9);
	x.InitializeGrid(2,0);
	
	ASSERT_EQ(x.GetPopulation(), 4);
}
TEST(Life, life_pop_2)
{
	Life<FredkinCell> x(5,10);
	
	x.InitializeGrid(0,0);
	x.InitializeGrid(1,1);
	x.InitializeGrid(0,9);
	x.InitializeGrid(4,0);
	
	ASSERT_EQ(x.GetPopulation(), 4);
}
TEST(Life, life_pop_3)
{
	Life<Cell> x(5,10);
	
	x.InitializeGrid(0,0, CONWAY);
	x.InitializeGrid(1,1, CONWAY);
	x.InitializeGrid(0,9, FREDKIN);
	x.InitializeGrid(4,9, FREDKIN);
	
	ASSERT_EQ(x.GetPopulation(), 4);
}

// ----
//  Test << Operation Grid
// ----

TEST(Life, life_write_1) 
{
	Life<ConwayCell> x(1,1);
	x.InitializeGrid(0,0);
	
	std::ostringstream w;
    w << x;
	ASSERT_EQ("\nGeneration = 0, Population = 1.\n*\n", w.str());
}

TEST(Life, life_write_2) 
{
	Life<FredkinCell> x(1,1);
	x.InitializeGrid(0,0);
	
	std::ostringstream w;
    w << x;
	ASSERT_EQ("\nGeneration = 0, Population = 1.\n0\n", w.str());
}

TEST(Life, life_write_3) 
{
	Life<Cell> x(1,2);
	x.InitializeGrid(0,0, CONWAY);
	x.InitializeGrid(0, 1, FREDKIN);
	
	std::ostringstream w;
    w << x;
	ASSERT_EQ("\nGeneration = 0, Population = 2.\n*0\n", w.str());
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

TEST(Life, life_init_3) 
{
	Life<Cell> x(12,15);
	
	x.InitializeGrid(0,0, CONWAY);
	x.InitializeGrid(11,14, FREDKIN);
	
	ASSERT_EQ(x.grid[0][0].IsAlive(), true);
	ASSERT_EQ(x.grid[11][14].IsAlive(), true);
	
	ASSERT_EQ(x.grid[0][0].GetCellType(), CONWAY);
	ASSERT_EQ(x.grid[11][14].GetCellType(), FREDKIN);
}

// ----
//  Test NextGeneration Function
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

TEST(Life, conway_evolve_6) 
{
	ConwayCell cc;
	
	cc.alive = true;
	cc.neighbors = 5;
	cc.type = CONWAY;
	
	cc.Evolve();
	
	ASSERT_EQ(cc.alive, false);
}

// ----
//  Test <<
// ----
TEST(Life, conway_write_1) 
{
	ConwayCell cc;
	
	std::ostringstream w;
    w << cc;
	ASSERT_EQ(".", w.str());
}

TEST(Life, conway_write_2) 
{
	ConwayCell cc;
	cc.BecomeAlive();
	
	std::ostringstream w;
    w << cc;
	ASSERT_EQ("*", w.str());
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

// ----
//  Test <<
// ----

TEST(Life, fredkin_write_1) 
{
	FredkinCell fc;
	
	std::ostringstream w;
    w << fc;
	ASSERT_EQ("-", w.str());
}

TEST(Life, fredkin_write_2) 
{
	FredkinCell fc;
	fc.BecomeAlive();
	
	std::ostringstream w;
    w << fc;
	ASSERT_EQ("0", w.str());
}

TEST(Life, fredkin_write_3) 
{
	FredkinCell fc;
	fc.BecomeAlive();
	fc.age = 5;
	
	std::ostringstream w;
    w << fc;
	ASSERT_EQ("5", w.str());
}

TEST(Life, fredkin_write_4) 
{
	FredkinCell fc;
	fc.BecomeAlive();
	fc.age = 11;
	
	std::ostringstream w;
    w << fc;
	ASSERT_EQ("+", w.str());
}

TEST(Life, fredkin_age_1) 
{
	FredkinCell fc;
	fc.BecomeAlive();
	fc.age = 11;
	
	ASSERT_EQ(11, fc.GetAge());
}

// -----------
// Test Abstract Cell
// -----------

// ----
//  Test BecomeAlive
// ----

TEST(Life, abstract_alive_1) 
{
	FredkinCell fc;

	ASSERT_EQ(fc.alive, false);
	
	fc.BecomeAlive();
	
	ASSERT_EQ(fc.alive, true);
}

TEST(Life, abstract_alive_2) 
{
	ConwayCell cc;

	ASSERT_EQ(cc.alive, false);
	
	cc.BecomeAlive();
	
	ASSERT_EQ(cc.alive, true);
}

// ----
//  Test IsAlive
// ----

TEST(Life, abstract_is_alive_1) 
{
	FredkinCell fc;
	ASSERT_EQ(fc.IsAlive(), false);
}

TEST(Life, abstract_is_alive_2) 
{
	ConwayCell cc;
	cc.BecomeAlive();
	ASSERT_EQ(cc.IsAlive(), true);
}

TEST(Life, abstract_is_alive_3) 
{
	ConwayCell cc;
	ASSERT_EQ(cc.IsAlive(), false);
}

// ----
//  Test IncrementNeighbors
// ----

TEST(Life, abstract_inc_neighbors_1) 
{
	FredkinCell fc;
	fc.IncrementNeighbors();
	ASSERT_EQ(fc.neighbors, 1);
}

TEST(Life, abstract_inc_neighbors_2) 
{
	ConwayCell cc;
	cc.IncrementNeighbors();
	cc.IncrementNeighbors();
	ASSERT_EQ(cc.neighbors, 2);
}

// ----
//  Test ResetNeighbors
// ----

TEST(Life, abstract_res_neighbors_1) 
{
	FredkinCell fc;
	fc.neighbors = 32;
	fc.ResetNeighbors();
	ASSERT_EQ(fc.neighbors, 0);
}

TEST(Life, abstract_res_neighbors_2) 
{
	ConwayCell cc;
	cc.neighbors = 8;
	cc.ResetNeighbors();
	ASSERT_EQ(cc.neighbors, 0);
}

// ----
//  Test GetType
// ----

TEST(Life, abstract_type_1) 
{
	FredkinCell fc;
	ASSERT_EQ(fc.GetCellType(), FREDKIN);
}

TEST(Life, abstract_type_2) 
{
	ConwayCell cc;
	ASSERT_EQ(cc.GetCellType(), CONWAY);
}

// -----------
// Test Cell
// -----------

// ----
//  Test Constructor
// ----

TEST(Life, cell_constructor_1) 
{
		Cell c;
		ASSERT_EQ(c.GetCellType(), FREDKIN);
}

// ----
//  Test Copy Constructor
// ----

TEST(Life, cell_copy_1) 
{
	Cell c(new ConwayCell());
	ASSERT_EQ(c.GetCellType(), CONWAY);
}

TEST(Life, cell_copy_2) 
{
	Cell c(new FredkinCell());
	ASSERT_EQ(c.GetCellType(), FREDKIN);
}

// ----
//  Test <<
// ----

TEST(Life, cell_write_1) 
{
	Cell c;
	
	std::ostringstream w;
    w << c;
	ASSERT_EQ("-", w.str());
}

TEST(Life, cell_write_2) 
{
	Cell c(new ConwayCell());
	
	std::ostringstream w;
    w << c;
	ASSERT_EQ(".", w.str());
}

TEST(Life, cell_write_3) 
{
	Cell c(new ConwayCell());
	c.BecomeAlive();
	
	std::ostringstream w;
    w << c;
	ASSERT_EQ("*", w.str());
}

TEST(Life, cell_write_4) 
{
	Cell c(new FredkinCell());
	c.BecomeAlive();
	
	std::ostringstream w;
    w << c;
	ASSERT_EQ("0", w.str());
}

// ----
//  Test BecomeAlive
// ----

TEST(Life, cell_alive_1) 
{
	Cell c(new FredkinCell());
	
	c.BecomeAlive();
	
	ASSERT_EQ(c.IsAlive(), true);
}

TEST(Life, cell_alive_2) 
{
	Cell c(new ConwayCell());
	
	c.BecomeAlive();
	
	ASSERT_EQ(c.IsAlive(), true);
}

TEST(Life, cell_alive_3) 
{
	Cell c;
	
	c.BecomeAlive();
	
	ASSERT_EQ(c.IsAlive(), true);
}

// ----
//  Test IsAlive
// ----

TEST(Life, cell_is_alive_1) 
{
	Cell c(new FredkinCell());
	
	ASSERT_EQ(c.IsAlive(), false);
}

TEST(Life, cell_is_alive_2) 
{
	Cell c(new ConwayCell());
	
	ASSERT_EQ(c.IsAlive(), false);
}

TEST(Life, cell_is_alive_3) 
{
	Cell c(new FredkinCell());
	
	c.BecomeAlive();
	
	ASSERT_EQ(c.IsAlive(), true);
}

// ----
//  Test IncrementNeighbors
// ----

TEST(Life, cell_inc_neighbors_1)
{
	Cell c(new FredkinCell());
	
	c.IncrementNeighbors();
	
	ASSERT_EQ(c.get()->neighbors, 1);
}

TEST(Life, cell_inc_neighbors_2)
{
	Cell c(new ConwayCell());
	
	c.IncrementNeighbors();
	
	ASSERT_EQ(c.get()->neighbors, 1);
}

TEST(Life, cell_inc_neighbors_3)
{
	Cell c;
	
	c.IncrementNeighbors();
	
	ASSERT_EQ(c.get()->neighbors, 1);
}

// ----
//  Test ResetNeighbors
// ----

TEST(Life, cell_res_neighbors_1)
{
	Cell c(new ConwayCell());
	
	c.get()->neighbors = 8;
	c.ResetNeighbors();
	
	ASSERT_EQ(c.get()->neighbors, 0);
}

TEST(Life, cell_res_neighbors_2)
{
	Cell c(new FredkinCell());
	
	c.get()->neighbors = 8;
	c.ResetNeighbors();
	
	ASSERT_EQ(c.get()->neighbors, 0);
}

TEST(Life, cell_res_neighbors_3)
{
	Cell c(new ConwayCell());
	
	c.IncrementNeighbors();
	c.ResetNeighbors();
	
	ASSERT_EQ(c.get()->neighbors, 0);
}

// ----
//  Test GetCellType
// ----

TEST(Life, cell_type_1) 
{
		Cell c;
		ASSERT_EQ(c.GetCellType(), FREDKIN);
}

TEST(Life, cell_type_2) 
{
	Cell c(new ConwayCell());
	ASSERT_EQ(c.GetCellType(), CONWAY);
}

TEST(Life, cell_type_3) 
{
	Cell c(new FredkinCell());
	ASSERT_EQ(c.GetCellType(), FREDKIN);
}

// ----
//  Test Evolve
// ----


TEST(Life, cell_evolve_1) 
{
	Cell c(new ConwayCell);
	
	c.get()->alive = true;
	c.get()->neighbors = 1;
	
	c.Evolve();
	
	ASSERT_EQ(c.get()->alive, false);
}

TEST(Life, cell_evolve_2) 
{
	Cell c(new ConwayCell);
	
	c.get()->alive = true;
	c.get()->neighbors = 2;
	
	c.Evolve();
	
	ASSERT_EQ(c.get()->alive, true);
}

TEST(Life, cell_evolve_3) 
{
	Cell c(new ConwayCell);
	
	c.get()->alive = false;
	c.get()->neighbors = 3;
	
	c.Evolve();
	
	ASSERT_EQ(c.get()->alive, true);
}

TEST(Life, cell_evolve_4) 
{
	Cell c(new FredkinCell);
	
	c.get()->alive = true;
	c.get()->neighbors = 2;
	c.get()->type = FREDKIN;
	
	c.Evolve();
	
	ASSERT_EQ(c.get()->alive, false);
}

TEST(Life, cell_evolve_5) 
{
	Cell c(new FredkinCell);
	
	c.get()->alive = false;
	c.get()->neighbors = 1;
	c.get()->type = FREDKIN;
	
	c.Evolve();
	
	ASSERT_EQ(c.get()->alive, true);
}

TEST(Life, cell_evolve_6) 
{
	Cell c(new FredkinCell);
	
	c.get()->alive = true;
	c.get()->neighbors = 1;
	c.get()->type = FREDKIN;
	
	c.Evolve();
	
	ASSERT_EQ(c.get()->alive, true);
	ASSERT_EQ(c.GetCellType(), FREDKIN);
		
	c.Evolve();
	
	ASSERT_EQ(c.get()->alive, true);
	ASSERT_EQ(c.GetCellType(), CONWAY);
}

