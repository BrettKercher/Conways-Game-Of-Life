#include <vector>
#include <utility>

enum CELLTYPE { CONWAY, FREDKIN } ;

template <typename T> 
class Life
{
	private:
		std::vector< std::vector<T> > grid; //n = y, m = x
		int n;
		int m;
	public:
		Life(int _n, int _m): n(_n), m(_m), grid( _n, std::vector<T>(_m)) {}
		
		void InitializeGrid(int n, int m) 
		{
			grid[n][m].BecomeAlive();
		}
		
		void NextGeneration() 
		{
			//first pass - skip dead guys, increment count of neighbors
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(grid[n][m].IsAlive())
					{
						grid[n][m].NotifyNeighbors();
					}
				}
			}
			
			//second pass - check neighbor count, perform rules
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					grid[n][m].Evolve();
				}
			}
		}
};

class AbstractCell
{
	private:
		CELLTYPE type;
		bool alive;
		int neighbors;
	public:
		AbstractCell();
		virtual void Evolve();
		virtual void NotifyNeighbors();
		void BecomeAlive();
		bool IsAlive();
};

class ConwayCell : AbstractCell
{
	private:
		
	public:
		ConwayCell();
		void Evolve();
		void NotifyNeighbors();
};

class FredkinCell : AbstractCell
{
	private:
		int age;
	public:
		FredkinCell();
		void Evolve();
		void NotifyNeighbors();
};