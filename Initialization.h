#pragma once


// Το IBC δηλώνει ποιες είναι οι συνθήκες ορίων.
// 1, στο αριστερό άκρο, η U έχει την τιμή UL,
// στο δεξί άκρο, η U' έχει την τιμή UR.
// 2, στο αριστερό άκρο, η U' έχει την τιμή UL,
// στο δεξί άκρο, η U έχει την τιμή UR.
// 3, στο αριστερό άκρο, η U έχει την τιμή UL,
// και στο δεξί άκρο, η U έχει την τιμή UR.
// 4, στο αριστερό άκρο, η U' έχει την τιμή UL,
// στο δεξί άκρο, η U' έχει την τιμή UR.

class Initialization
{
public:

	Initialization();

	double setFf(double x);

	double setPp(double x);

	double setQq(double x);

	double setRealValue(double x);
	
};

