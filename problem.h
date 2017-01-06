#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <vector>

using std::vector;

/*		
		index = 0 Rosenbrock
		index = 1 Rastrigin
		index = 2 Ackley
		index = 3 Schwefel
		index = 4 Schaffer
		index = 5 Weierstrass
*/

class Problem
{
	private:
		double _LowerLimit, _UpperLimit;
		int _index;
		int _dimension;
			
	public:
		Problem(int index, double LowerLimit, double UpperLimit); //constructeur probleme
		Problem(const Problem& pbm);
		
		int getIndex() const;			
		double getUpper() const;		
		double getLower() const;	
		int dimension() const;	
		
		void index(int index);
		void Upper(double up);		
		void Lower(double low);
		void dimension(int dimension);	
			
};

#endif
