#include <iostream>
#include "MyAlgorithm.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int choix = 0;
	do
	{
		cout<<"Rosenbrock : 0\nRastrigin : 1\nAckley : 2\nSchwefel : 3\nSchaffer : 4\nWeierstrass : 5\n\nVotre choix : ";
		cin>>choix;
	}
	while(choix < 0 || choix > 5);

	Problem prob(choix, -3, 3);
	SetUpParams param(prob.dimension(),0.9,0.99,0.3);
	MyAlgorithm ma(prob,param);
	ma.HarmonySearch();

	return 0;
	system("PAUSE"); 
}

