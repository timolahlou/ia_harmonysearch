#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <cmath>

#include "problem.h"

using namespace std;

class Solution
{
	private:
		double _current_fitness;
		vector<double> _solution;
		Problem _pbm;

	public:
		Solution(const Problem& pbm);
		
		void initialize();
		
		double 	fitness();			//calcule la fitness, modifie la valeur de _current_fitness et retourne sa valeur
		double get_fitness();		//retourne la valeur stocké dans _current_fitness
		
		vector<double>& solution();
		const Problem& pbm() const;

		double& position(int index); 
		void  insert_position(int index, double value);	
		void insert(double value);
};

#endif
