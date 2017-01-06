#include "MyAlgorithm.h"

#include <float.h>
#include <ctime>

MyAlgorithm::MyAlgorithm(const Problem& pbm,SetUpParams& stp) : _setup{stp}
{
	initialize(pbm);
}

MyAlgorithm::~MyAlgorithm()
{
	for(int i=0; i<_solutions.size(); i++)
	{
		delete _solutions[i];
	}
	_solutions.clear();
}

void MyAlgorithm::initialize(const Problem& pbm)
{
	int seed = static_cast<int>(time(0));
	srand(seed);
	for (int i = 0; i < _setup.population_size(); i++)
	{
		_solutions.push_back(new Solution(pbm));
	}
}

void MyAlgorithm::evaluate()
{
	_upper_cost = 0;
	_lower_cost = 0;
	for(int i=0; i<_solutions.size(); i++)
	{
		_solutions[i]->fitness();
		if(best_cost() > _solutions[i]->get_fitness())	{	_lower_cost = i;	}
		if(worst_cost() < _solutions[i]->get_fitness())	{	_upper_cost = i;	}
	}
}

Solution* MyAlgorithm::evolution()
{
	Solution* S = new Solution(_solutions[0]->pbm());
	
	for (int i = 0; i < _setup.solution_size(); i++) 
	{
		if ( ((double)rand() / RAND_MAX) < _setup.hmcr()) 
		{
			int randomHarmony = _setup.population_size() * rand() / RAND_MAX;
			if(randomHarmony == 30) randomHarmony = 29;		//parfois on obtient rand() / RAND_MAX = 1 et donc randomHarmony = 30 
			S->insert(_solutions[randomHarmony]->position(i));
			if ( ((double)rand() / RAND_MAX) < _setup.par())
			{
				double temp = S->position(i);
				if (((double)rand() / (RAND_MAX)) < 0.5) 
				{
					temp = best_solution().position(i) + ((double)rand() / (RAND_MAX)) * _setup.bw();
					if (temp <= S->pbm().getUpper())	S->insert_position(i,temp);
					else S->insert_position(i,S->pbm().getUpper());
				}
				else 
				{
					temp = best_solution().position(i) - ((double)rand() / (RAND_MAX)) * _setup.bw();
					if (temp >= S->pbm().getLower())	S->insert_position(i,temp);
					else S->insert_position(i,S->pbm().getLower());
				}
			}	
		}
		else	
		{
			S->insert(S->pbm().getLower() + (S->pbm().getUpper()-S->pbm().getLower()) * rand() / RAND_MAX);
		}
	}
	S->fitness();
	return S;
}

void MyAlgorithm::HarmonySearch()
{
	vector<double> Historique;
	
	double best_fitness = DBL_MAX; // max double 
	double moyenne = 0;
	double ecart =0;
	
	for(int i=0; i<_setup.independent_runs(); i++)
	{
		for(int j=0; j<_setup.nb_evolution_steps(); j++)
		{	
			evaluate();
			Solution* S = evolution();
			if(S->get_fitness() < worst_cost())
			{
				Solution* temp = _solutions[_upper_cost];
				_solutions[_upper_cost] = S;
				delete(temp);	
			}
			S = nullptr;
		}
		evaluate();
		if(best_fitness > best_cost())
		{
			best_fitness = best_cost();
		}
		Historique.push_back(best_cost());
		cout<<"independent run "<<i<<": la meilleur fitness est : "<<Historique[i]<<endl;
	}
	cout<<"\nla meilleur fitness est : "<<best_fitness;
	
	for(int i=0; i<Historique.size(); i++)
	{
		moyenne += Historique[i]/30;
	}
	cout<<"\nla moyenne est : "<<moyenne;
	
	for(int i=0; i<Historique.size(); i++)
	{
		ecart += pow(Historique[i],2);
	}
	ecart = sqrt(ecart/30 - pow(moyenne,2));
	cout<<"\nl'ecart type est : "<<ecart;
}

SetUpParams& MyAlgorithm::setup()
{
	return _setup;
}

vector<Solution*>& MyAlgorithm::solutions()
{
	return _solutions;
}

int MyAlgorithm::upper_cost() const
{
	return _upper_cost;
}

int MyAlgorithm::lower_cost() const
{
	return _lower_cost;
}

Solution& MyAlgorithm::solution(int i)
{
	return (*_solutions[i]);
}

double MyAlgorithm::fitness(int i) const
{
	return _solutions[i]->get_fitness();
}

double MyAlgorithm::best_cost() const
{
	return fitness(lower_cost());
}

double MyAlgorithm::worst_cost() const
{
	return fitness(upper_cost());
}

Solution& MyAlgorithm::best_solution() const
{
	return (*_solutions[lower_cost()]);
}

Solution& MyAlgorithm::worst_solution() const
{
	return (*_solutions[upper_cost()]);
}
