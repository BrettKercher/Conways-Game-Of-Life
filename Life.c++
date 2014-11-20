#include <vector>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <stdexcept>

#include "Life.h"

// ---------
// AbstractCell Functions
// ---------

AbstractCell::AbstractCell() : type(CONWAY), alive(false)
{
}

void AbstractCell::Evolve()
{
}

void AbstractCell::NotifyNeighbors()
{
}

void AbstractCell::BecomeAlive()
{
}

bool AbstractCell::IsAlive()
{
	return false;
}

// ---------
// ConwayCell Functions
// ---------

ConwayCell::ConwayCell() 
{
	
}

void ConwayCell::Evolve() 
{
	
}

void ConwayCell::NotifyNeighbors() 
{
	
}

// ---------
// FredkinCell Functions
// ---------

FredkinCell::FredkinCell() 
{
	
}

void FredkinCell::Evolve() 
{
	
}

void FredkinCell::NotifyNeighbors() 
{
	
}