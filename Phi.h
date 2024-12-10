#pragma once
#include "Initialization.h"
//  Purpose:
//
//    PHI evaluates a linear basis function and its derivative.
class Phi : public Initialization
{
public:

	Phi();

	void phi(const int il, const double x, double* phii, double* phiix, const double xl, const double xr);

};

