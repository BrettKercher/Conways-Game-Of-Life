#include <vector>
#include <utility>

template <typename T> 
class Life
{
	private:
		std::vector<T> grid;
	public:
		void InitializeGrid();
		void Evolve();
		int CountNeighbors();
};

class AbstractCell
{
	
};

class ConwayCell
{
	
};

class FredkinCell
{
	
};