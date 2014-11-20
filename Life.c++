#include <vector>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <stdexcept>

#include "Life.h"

// ---------
// AbstractCell Functions
// ---------

AbstractCell::AbstractCell() : type(CONWAY), alive(false) {}

void AbstractCell::BecomeAlive()
{
	alive = true;
}

bool AbstractCell::IsAlive()
{
	return alive;
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