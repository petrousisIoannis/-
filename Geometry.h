#pragma once
#include "Initialization.h"



class Geometry : public Initialization

{
public:
	
	Geometry();

	void partion(double part[], const double xl, const double xr, double h[], double xquad[], const int nsub, const int ibc);

	void node(int* nu, int  node[], int indx[], const int nsub, const int ibc);//  Set the value of NODE, which records, for each interval, //  the node numbers at the left and right.


};

