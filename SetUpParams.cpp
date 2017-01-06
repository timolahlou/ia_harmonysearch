#include "SetUpParams.h"

SetUpParams::SetUpParams(int solution_size, double par, double hmcr, double bw) : _independent_runs{30},
																				  _nb_evolution_steps{66666},
																				  _population_size{30},
																				  _solution_size{solution_size},
																				  PAR{par},
																				  HMCR{hmcr},
																				  BW{bw}
{
	
}

const int SetUpParams::independent_runs() const
{
	return _independent_runs;
}

const int SetUpParams::nb_evolution_steps() const
{
	return _nb_evolution_steps;
}

const int SetUpParams::population_size() const
{
	return _population_size;
}

const int SetUpParams::solution_size() const
{
	return _solution_size;
}

const double SetUpParams::hmcr() const
{
	return HMCR;
}

const double SetUpParams::bw() const
{
	return BW;
}

const double SetUpParams::par() const
{
	return PAR;
}

void SetUpParams::independent_runs(const int val)
{
	_independent_runs = val;
}

void SetUpParams::nb_evolution_steps(const int val)
{
	_nb_evolution_steps = val;
}

void SetUpParams::population_size(const int val)
{
	_population_size = val;
}

void SetUpParams::solution_size(const int val)
{
	_solution_size = val;
}

void SetUpParams::setHMCR(double hmcr)
{
	HMCR = hmcr;
}

void SetUpParams::setBW(double bw)
{
	BW = bw;
}

void SetUpParams::setPAR(double par)
{
	PAR = par;
}
