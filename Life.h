#include <vector>
#include <utility>
#include "gtest/gtest_prod.h"

enum CELLTYPE { CONWAY, FREDKIN } ;

template <typename T> 
class Life
{
	private:
		std::vector< std::vector<T> > grid; //n = y, m = x
		int n;
		int m;
		
		void NotifyNeighbors(int y, int x, bool Conway)
		{
			if(Conway)
			{
				for(int i = y-1; i <= y+1; i++)
				{
					for(int j = x-1; j <= x+1; j++)
					{
						if(i >= 0 && i < n && j >= 0 && j < m)
						{
							if(i == y && j == x) 
							{}
							else
								grid[i][j].IncrementNeighbors();
						}
					}
				}
			}
			else if(!Conway)
			{
				if( (y+1) < n)
					grid[y+1][x].IncrementNeighbors();
				if( (y-1) >= 0)
					grid[y-1][x].IncrementNeighbors();
				
				if( (x+1) < m)
					grid[y][x+1].IncrementNeighbors();
				if( (x-1) >= 0)
					grid[y][x-1].IncrementNeighbors();
			}
		}
		
	public:
		Life(int _n, int _m): grid( _n, std::vector<T>(_m)), n(_n), m(_m)  {}
		
		void InitializeGrid(int n, int m) 
		{
			grid[n][m].BecomeAlive();
		}
		
		void NextGeneration() 
		{
			//first pass - skip dead guys, increment count of neighbors
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(grid[i][j].IsAlive())
					{
						if(grid[i][j].GetCellType() == CONWAY)
						{
							NotifyNeighbors(i, j, true);
						}
						else if(grid[i][j].GetCellType() == FREDKIN)
						{
							NotifyNeighbors(i, j, false);
						}
					}
				}
			}
			
			//second pass - check neighbor count, perform rules
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					
					grid[i][j].Evolve();
					grid[i][j].ResetNeighbors();
				}
			}
		}
		
	private:
		FRIEND_TEST(Life, life_notify_1);
		FRIEND_TEST(Life, life_notify_2);
		FRIEND_TEST(Life, life_notify_3);
		FRIEND_TEST(Life, life_notify_4);
		FRIEND_TEST(Life, life_notify_5);
		FRIEND_TEST(Life, life_notify_6);
		FRIEND_TEST(Life, life_notify_7);
		FRIEND_TEST(Life, life_constructor_1);
		FRIEND_TEST(Life, life_constructor_2);
		FRIEND_TEST(Life, life_init_1);
		FRIEND_TEST(Life, life_init_2);
		FRIEND_TEST(Life, life_next_gen_1);
		FRIEND_TEST(Life, life_next_gen_2);
		FRIEND_TEST(Life, life_next_gen_3);
};

class AbstractCell
{
	protected:
		CELLTYPE type;
		bool alive;
		int neighbors;
	public:
		AbstractCell();
		AbstractCell(CELLTYPE t);
		virtual void Evolve() = 0;
		void BecomeAlive();
		bool IsAlive();
		void IncrementNeighbors();
		void ResetNeighbors();
		CELLTYPE GetCellType();
		
	private:
		FRIEND_TEST(Life, life_notify_1);
		FRIEND_TEST(Life, life_notify_2);
		FRIEND_TEST(Life, life_notify_3);
		FRIEND_TEST(Life, life_notify_4);
		FRIEND_TEST(Life, life_notify_5);
		FRIEND_TEST(Life, life_notify_6);
		FRIEND_TEST(Life, life_notify_7);
};

class ConwayCell : public AbstractCell
{
	private:
		
	public:
		ConwayCell();
		void Evolve();
};

class FredkinCell : public AbstractCell
{
	private:
		int age;
	public:
		FredkinCell();
		void Evolve();
};