#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H

#include <iostream>

using namespace std;

class SetUpParams
{
	private:
		int   _independent_runs;	//nombre total d'iterations : 30 
		int   _nb_evolution_steps;	//nombre d'iterations par solution : 2 e^6 / 30 = 66666
		int   _population_size;		//taille de la poplation c a d nombre de solutions : 30
		int   _solution_size;		//taille d'une solution
    	double PAR;					//valeur minimale qu'il faut obtenir pour pouvoir modifier un vecteur (entre 0 et 1)
		double BW;					//valeur d'écart
		double HMCR;				//valeur minimale qu'il faut obtenir pour créer un nouveau vecteur (entre 0 et 1)
    
	public:
		SetUpParams(int solution_size, double par, double hmcr, double bw);		//constructeur
		
		const int   independent_runs() const;			//getter
		const int   nb_evolution_steps() const;			//getter
		const int   population_size() const;			//getter
		const int   solution_size() const;				//getter
		const double hmcr() const;						//getter
		const double bw() const;						//getter
		const double par() const;						//getter
		
		void independent_runs(const int val);			//setter
		void nb_evolution_steps(const int val);			//setter
		void population_size(const int val);			//setter
		void solution_size(const int val);				//setter
		void setHMCR(double hmcr);						//setter
		void setBW(double bw);							//setter
		void setPAR(double par);						//setter
};

#endif
