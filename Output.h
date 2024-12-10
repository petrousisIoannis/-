#pragma once
#include "Assemble.h"


class Output : public Assemble
{
public:
	
	
	Output();

	void output(double f[], int indx[], const int nu, const double ul, const double ur, double xn[], const int nsub, const int ibc, double real[], double h[]);

	void printsDiagLinearSys(double adiag[], double aleft[], double arite[], double f[],const int nu);

private:

	double u;

	Initialization init;



};


