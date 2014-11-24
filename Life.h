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
		int generation;
		
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
		
		int GetPopulation() const
		{
			int pop = 0;
			
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(grid[i][j].IsAlive())
						pop++;
				}
			}
			
			return pop;
		}
		
	public:
		Life(int _n, int _m): grid( _n, std::vector<T>(_m)), n(_n), m(_m), generation(0)  {}
		
		friend std::ostream& operator<<( std::ostream& o, const Life& l) 
		{
			o << std::endl << "Generation: " << l.generation << ", Population: " << l.GetPopulation() << "." << std::endl;
			
			for(int i = 0; i < l.n; i++)
			{
				for(int j = 0; j < l.m; j++)
				{
					o << l.grid[i][j];
				}
				o << std::endl;
			}
			
			return o;
		}
		
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
			
			generation++;
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
		bool IsAlive() const;
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
		FRIEND_TEST(Life, abstract_alive_1);
		FRIEND_TEST(Life, abstract_alive_2);
		FRIEND_TEST(Life, abstract_alive_3);
		FRIEND_TEST(Life, abstract_inc_neighbors_1);
		FRIEND_TEST(Life, abstract_inc_neighbors_2);
		FRIEND_TEST(Life, abstract_inc_neighbors_3);
		FRIEND_TEST(Life, abstract_res_neighbors_1);
		FRIEND_TEST(Life, abstract_res_neighbors_2);
		FRIEND_TEST(Life, abstract_res_neighbors_3);
		
};

class ConwayCell : public AbstractCell
{
	private:
		
	public:
		ConwayCell();
		void Evolve();
		friend std::ostream& operator<<( std::ostream& o, const ConwayCell& cc);
	private:
		FRIEND_TEST(Life, conway_constructor_1);
		FRIEND_TEST(Life, conway_evolve_1);
		FRIEND_TEST(Life, conway_evolve_2);
		FRIEND_TEST(Life, conway_evolve_3);
		FRIEND_TEST(Life, conway_evolve_4);
		FRIEND_TEST(Life, conway_evolve_5);
};

class FredkinCell : public AbstractCell
{
	private:
		int age;
	public:
		FredkinCell();
		void Evolve();
		friend std::ostream& operator<<( std::ostream& o, const FredkinCell& fc);
		
	private:
		FRIEND_TEST(Life, fredkin_constructor_1);
		FRIEND_TEST(Life, fredkin_evolve_1);
		FRIEND_TEST(Life, fredkin_evolve_2);
		FRIEND_TEST(Life, fredkin_evolve_3);
		FRIEND_TEST(Life, fredkin_evolve_4);
		FRIEND_TEST(Life, fredkin_evolve_5);
		FRIEND_TEST(Life, fredkin_evolve_6);
};