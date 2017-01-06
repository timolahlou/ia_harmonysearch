#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include "solution.h"
#include "SetUpParams.h"

using namespace std;

class MyAlgorithm
{
	private:
		vector<Solution*> _solutions;
		SetUpParams _setup;
		int _upper_cost,_lower_cost; 	// index des solutions avec la plus mauvaise et la meilleur fitness

	public:
		
		MyAlgorithm(const Problem& pbm,SetUpParams& stp); 
		~MyAlgorithm();
		
	  	void initialize(const Problem& pbm);
 
        void evaluate();
	 
		SetUpParams& setup();
		vector<Solution*>& solutions();
		int upper_cost() const;
		int lower_cost() const;
		Solution& solution(int index);
        double fitness(int index) const;
		double best_cost() const;
		double worst_cost() const;
		Solution& best_solution() const;
		Solution& worst_solution() const;
		
		Solution* evolution(); 		//makes an evolution step
		void HarmonySearch(); 		//lance l'algorithme
};
  
#endif
