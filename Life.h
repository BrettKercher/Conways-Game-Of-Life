#include <vector>
#include <utility>

enum CELLTYPE { CONWAY, FREDKIN } ;

template <typename T> 
class Life
{
	private:
		std::vector< std::vector<T> > grid;
		int n;
		int m;
	public:
		Life() {}
		void InitializeGrid() {}
		void NextGeneration() {}
		int CountNeighbors(int x, int y) 
		{
			return 0;
		}
};

class AbstractCell
{
	private:
		CELLTYPE type;
		bool alive;
	public:
		virtual void Evolve();
};

class ConwayCell
{
	
};

class FredkinCell
{
	
};