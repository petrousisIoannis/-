#include "Initialization.h"
#include<iostream>
#define pi 3.14159265359


Initialization::Initialization() {};

//Θέτουμε την συνάρτηση η οποία είναι αρμόδια για την προσεγγιστική λύση της μερικής διαφορικής εξίσωσης -pu'' + qu = f.
double Initialization::setFf(const double x)
{
	double value;
	
	value = /*((4 * pow(pi, 2) * sin(2 * pi * x) + pow(pi, 2)) * sin(2 * pi * x));*/ -pow(10, -3) * (exp(-x) * ((1 - pow(pi, 2)) * sin(pi * x) - 2 * pi * cos(pi * x))) + exp(-x) * sin(pi * x);

	return value;

}

//Θέτουμε την συνάρτηση η οποία είναι αρμόδια για το p της μερικής διαφορικής εξίσωσης -pu'' + qu = f. 
double Initialization::setPp(const double x)
{
	double value;

	value = pow(10, -3); /*1;*/

	return value;

}

//Θέτουμε την συνάρτηση η οποία είναι αρμόδια για την q της μερικής διαφορικής εξίσωσης -pu'' + qu = f. 
double Initialization::setQq(const double x)
{
	double value;

	value = 1; /*pow(pi, 2);*/
	
	return value;
}

//Θέτουμε την συνάρτηση που είναι αρμόδια για την πραγματική λύση της μερικής διαφορικής εξίσωσης -pu'' + qu = f. 
double Initialization::setRealValue(const double x)
{
	double value;

	value = /*sin(2 * pi * x);*/ exp(-x) * sin(pi * x);

	return value;
}

