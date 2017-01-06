#include "problem.h"

Problem::Problem(int index, double Low, double Up) : _index{index}, _LowerLimit{Low}, _UpperLimit{Up}
{
	if(_index == 4) _dimension = 2;
	else _dimension = 30;
}

Problem::Problem(const Problem& pbm) : _index{pbm.getIndex()}, _LowerLimit{pbm.getLower()}, _UpperLimit{pbm.getUpper()}, _dimension{pbm.dimension()}
{
	
}

int Problem::getIndex() const
{
	return _index;
}

double Problem::getUpper() const
{
	return _UpperLimit;
}

double Problem::getLower() const
{
	return _LowerLimit;
}

int Problem::dimension() const
{
	return _dimension;
}

void Problem::index(int index)
{
	_index = index;
}

void Problem::Upper(double up)
{
	_UpperLimit = up;
}

void Problem::Lower(double low)
{
	_LowerLimit = low;
}

void Problem::dimension(int dimension)
{
	_dimension = dimension;
}
