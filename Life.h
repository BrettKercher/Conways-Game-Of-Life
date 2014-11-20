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
};

class AbstractCell
{
	private:
		CELLTYPE type;
		bool alive;
	public:
		virtual void Evolve();
		virtual int CountNeighbors();
};

class ConwayCell : AbstractCell
{
	private:
		
	public:
		ConwayCell() {}
		void Evolve();
		int CountNeighbors();
};

class FredkinCell : AbstractCell
{
	
};