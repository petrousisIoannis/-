#pragma once
#include "Assemble.h"

class Solve : public Assemble
{
public:

	Solve();

	void solve(double adiag[], double aleft[], double arite[], double f[], const int nu);


};


