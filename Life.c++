#include <vector>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <stdexcept>

#include "Life.h"

// ---------
// AbstractCell Functions
// ---------

AbstractCell::AbstractCell() : type(CONWAY), alive(false), neighbors(0) {}

AbstractCell::AbstractCell(CELLTYPE t) : type(t), alive(false), neighbors(0) {}

void AbstractCell::BecomeAlive()
{
	alive = true;
}

bool AbstractCell::IsAlive() const
{
	return alive;
}

CELLTYPE AbstractCell::GetCellType()
{
	return type;
}

void AbstractCell::IncrementNeighbors()
{
	this->neighbors++;
}

void AbstractCell::ResetNeighbors()
{
	neighbors = 0;
}

// ---------
// ConwayCell Functions
// ---------

ConwayCell::ConwayCell() : AbstractCell(CONWAY) {}

std::ostream& operator<<( std::ostream& o, const ConwayCell& cc)
{
	if(cc.IsAlive())
		o << '*';
	else
		o << '.';
	return o;
}

void ConwayCell::Evolve() 
{
	if(alive)
	{
		if(neighbors < 2 || neighbors > 3)
		{
			alive = false;
		}
	}
	else
	{
		if(neighbors == 3)
		{
			alive = true;
		}
	}
	
	//If neither of the above conditions pass, the cell remains in its same state
}

// ---------
// FredkinCell Functions
// ---------

FredkinCell::FredkinCell()  : AbstractCell(FREDKIN), age(0) {}

std::ostream& operator<<( std::ostream& o, const FredkinCell& fc)
{
	if(fc.IsAlive())
		if(fc.age > 9)
			o << '+';
		else
			o << fc.age;
	else
		o << '-';
	
	return o;
}

void FredkinCell::Evolve() 
{
	if(alive)
	{
		if(neighbors == 0 || neighbors == 2 || neighbors == 4)
		{
			alive = false;
		}
		else
		{
			age++;
		}
	}
	else
	{
		if(neighbors == 1 || neighbors == 3)
		{
			alive = true;
		}
	}
}