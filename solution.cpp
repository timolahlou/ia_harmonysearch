#include "solution.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

Solution::Solution(const Problem & pbm) : _pbm{pbm}
{
	initialize();
}

void Solution::initialize()
{
	for (int i = 0; i <_pbm.dimension(); i++)
	{	
		_solution.push_back(_pbm.getLower() + (_pbm.getUpper()-_pbm.getLower()) * std::rand() / RAND_MAX);
	}
	fitness(); 
}

const Problem& Solution::pbm() const
{
	return _pbm;
}

double Solution::get_fitness()
{
	return _current_fitness;
}

double Solution::fitness()
{
	double sum = 0.0;
	double temp1 = 0.0;
	double temp2 = 0.0;
	switch(_pbm.getIndex())
	{
		case 0: //Rosenbrock
  			for (int i=0; i<_pbm.dimension()-1 ; i++) 
			{
				
    			temp1 = (_solution[i] * _solution[i]) - _solution[i+1];
    			temp2 = _solution[i] - 1.0;
    			sum += (100.0 * temp1 * temp1) + (temp2 * temp2);
			}
			break;
			
		case 1: //rastrigin
			for (int i=0; i<_pbm.dimension(); i++) 
			{
    			sum += (_solution[i] * _solution[i]) - 10.0 * cos(2*M_PI*_solution[i]);
  			}
  			sum += 10 * _pbm.dimension();
  			break;
  			
  		case 2: //Ackley
  			for(int i=0; i<_pbm.dimension(); i++)
  			{
  				temp1 += _solution[i] * _solution[i];
  				temp2 += cos(2*M_PI*_solution[i]);
			}
			sum = -20 *exp(-0.2*sqrt(temp1/_pbm.dimension())) - exp(temp2/_pbm.dimension()) + 20 + exp(1);
			break;
			
		case 3: //Schwefel
			for(int i=0; i<_pbm.dimension();i++)
			{
				sum += _solution[i]*sin(sqrt(fabs(_solution[i])));
			}
			sum = 418.9829 * _pbm.dimension() - sum;
			break; 
			
		case 4: //Schaffer
			temp1 = sin(pow(_solution[0],2) - pow(_solution[1],2)) * sin(pow(_solution[0],2) - pow(_solution[1],2)) - 0.5;
			temp2 = (1 + 0.001 * (pow(_solution[0],2) + pow(_solution[1],2))) * (1 + 0.001 * (pow(_solution[0],2) + pow(_solution[1],2)));
			sum = 0.5 + temp1/temp2;
			break;
			
		case 5: //Weierstrass
			for(int i=0; i<_pbm.dimension(); i++)	
			{
				for(int j=0; j<20; j++)
				{
					temp1 += pow(0.5,j) * cos(2*M_PI*pow(3.0,j)*(_solution[i] + 0.5));
				}
			}
			for(int j=0; j<20; j++)
			{
				temp2 += pow(0.5,j) * cos(2*M_PI*pow(3.0,j)*0.5);
			}
			sum = temp1 - temp2 * _pbm.dimension();
	}
	_current_fitness = sum;
	return sum;
}

vector<double>& Solution::solution()
{
	return _solution;
}

double& Solution::position(int i)
{
	return _solution[i];
}

void Solution::insert_position(int i,double val)
{
	_solution[i] = val;
}

void Solution::insert(double val)
{
	_solution.push_back(val);
}
