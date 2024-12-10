#pragma once
#include "Phi.h"

class Assemble : public Phi
{
private:

    double aij;                 //TO OLOKLHRWMA GIA TO FINITE ELEMENT 
    double he;                  //MHKOS YPODIASTHMATOS
    double phii;                // to apotelesma twn synarthsewn vashs tou mikroterou oriou
    double phiix;               // h paragwgos twn synarthsewn vashs tou mikroterou oriou
    double phij;                // to apotelesma twn synarthsewn vashs tou megalyterou oriou
    double phijx;               // h paragwgos twn synarthsewn vashs tou megalyterou oriou
    double x;                   //
    double xl;                  //TO ARISTERO AKRO 
    double xquade;              //O ARITHMOS TWN TETRAGWNIKWN SHMEIWN(TO MISO ANAMESA STA YPODIASTHAMTA)
    double xr;                  //TO DEXI AKRO
    int ig;                     //
    int iu;                     //
    int jg;                     //
    int ju;                     //
    Initialization functions;   //OI SYNARTHSEIS POY XRHSIMOPOIOUME GIA THN MERIKH DIAFORIKH 
    Phi phi;                    //OI SYANRTHSEIS VASHS 

public:

	Assemble();

	void assemble(double f[], double arite[], double aleft[], double adiag[], double h[], int indx[], const int nl, int node[], const int nu, const double ul, const double ur,
        double part[], double xquad[], const int nQuad, const int nsub);


};

