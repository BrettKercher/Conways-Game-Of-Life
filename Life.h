#include <vector>
#include <utility>
#include <algorithm> // swap
#include "gtest/gtest_prod.h"

enum CELLTYPE { CONWAY, FREDKIN } ;

template <typename T> 
class Life
{
	public:
		std::vector< std::vector<T> > grid; //n = y, m = x
		int n;
		int m;
		int generation;
		
		void NotifyNeighbors(int y, int x, bool Conway)
		{
			if((y-1) >= 0 && (x-1) >= 0 && grid[y-1][x-1].GetCellType() == CONWAY)
				grid[y-1][x-1].IncrementNeighbors();
			
			if((y-1) >= 0 && (x+1) < m && grid[y-1][x+1].GetCellType() == CONWAY)
				grid[y-1][x+1].IncrementNeighbors();
			
			if((y+1) < n && (x-1) >= 0 && grid[y+1][x-1].GetCellType() == CONWAY)
				grid[y+1][x-1].IncrementNeighbors();
			
			if((y+1) < n && (x+1) < m && grid[y+1][x+1].GetCellType() == CONWAY)
				grid[y+1][x+1].IncrementNeighbors();
			
			if( y+1 < n)
				grid[y+1][x].IncrementNeighbors();
			if( y-1 >= 0)
				grid[y-1][x].IncrementNeighbors();
			if( x+1 < m)
				grid[y][x+1].IncrementNeighbors();
			if(x-1 >= 0)
				grid[y][x-1].IncrementNeighbors();

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
			o << std::endl << "Generation = " << l.generation << ", Population = " << l.GetPopulation() << "." << std::endl;
			
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
		
		void InitializeGrid(int n, int m, CELLTYPE t) 
		{
			grid[n][m].BecomeAlive(t);
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
		virtual ~AbstractCell () {}
		virtual void Evolve() = 0;
		void BecomeAlive();
		bool IsAlive() const;
		void IncrementNeighbors();
		void ResetNeighbors();
		CELLTYPE GetCellType() const;
		virtual AbstractCell* clone () const = 0;
		
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
		virtual ConwayCell* clone () const 
		{
            return new ConwayCell(*this);
		}
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
		int GetAge() { return age; }
		virtual FredkinCell* clone () const 
		{
            return new FredkinCell(*this);
		}
		
	private:
		FRIEND_TEST(Life, fredkin_constructor_1);
		FRIEND_TEST(Life, fredkin_evolve_1);
		FRIEND_TEST(Life, fredkin_evolve_2);
		FRIEND_TEST(Life, fredkin_evolve_3);
		FRIEND_TEST(Life, fredkin_evolve_4);
		FRIEND_TEST(Life, fredkin_evolve_5);
		FRIEND_TEST(Life, fredkin_evolve_6);
};

template <typename T>
class Handle 
{
    friend bool operator == (const Handle& lhs, const Handle& rhs) 
	{
        if (!lhs._p && !rhs._p)
            return true;
        if (!lhs._p || !rhs._p)
            return false;
        return (*lhs._p == *rhs._p);
		
	}

    friend bool operator != (const Handle& lhs, const Handle& rhs) 
	{
        return !(lhs == rhs);
	}

    public:
        typedef T                 value_type;
		
        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    private:
        pointer _p;

    protected:
        pointer get () 
		{
            return _p;
		}

        const_pointer get () const 
        {
            return _p;
		}
		
		void set(pointer p)
		{
			delete _p;
			_p = p;
		}

    public:
        Handle (pointer p) 
		{
            _p = p;
		}

        Handle (const Handle& that) 
		{
            if (!that._p)
                _p = 0;
            else
                _p = that._p->clone();
		}

        ~Handle () 
		{
            delete _p;
		}

        Handle& operator = (Handle that) 
		{
            swap(that);
            return *this;
		}

        void swap (Handle& that) 
		{
            std::swap(_p, that._p);
		}
};

class Cell : Handle<AbstractCell>
{
	public:
		Cell () : Handle<AbstractCell> ( new FredkinCell() ) {}
		Cell (AbstractCell* p) : Handle<AbstractCell> (p) {}
		
		friend std::ostream& operator<<( std::ostream& o, const Cell& c)
		{
			if(c.get()->GetCellType() == FREDKIN)
			{
				if(c.get()->IsAlive())
					o << ((FredkinCell*)(c.get()))->GetAge();
				else
					o << '-';
			}
			else if(c.get()->GetCellType() == CONWAY)
			{
				if(c.get()->IsAlive())
					o << '*';
				else
					o << '.';
			}
	
 			return o;
		}
		
		void BecomeAlive (CELLTYPE t) 
		{
			if(t == CONWAY)
				set(new ConwayCell());
			else if (t == FREDKIN)
				set(new FredkinCell());
			
			get()->BecomeAlive();
		}
		
		void BecomeAlive () 
		{
			get()->BecomeAlive();
		}
		bool IsAlive() const
		{
			return get()->IsAlive();
		}
		void IncrementNeighbors()
		{
			get()->IncrementNeighbors();
		}
		void ResetNeighbors()
		{
			get()->ResetNeighbors();
		}
		CELLTYPE GetCellType() const
		{
			return get()->GetCellType();
		}
		void Evolve()
		{
			get()->Evolve();
			
			if(get()->GetCellType() == FREDKIN)
			{
				if(((FredkinCell*)get())->GetAge() == 2)
				{
					set(new ConwayCell());
					get()->BecomeAlive();
				}
			}
		}
};