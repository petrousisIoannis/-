#include "Phi.h"

/* Aξιολογεί μια γραμμική συνάρτηση βάσης και την παράγωγό της.


// Input, int IL, ο δείκτης της συνάρτησης βάσης.
// 1, η συνάρτηση η οποία είναι 1 στο XLEFT και 0 στο XRITE.
// 2, η συνάρτηση που είναι 0 στο XLEFT και 1 στο XRITE.
//
// Input, double X, το σημείο αξιολόγησης.
//
// Input, double *PHII, *PHIIX, η τιμή του
// της συνάρτησης βάσης και της παραγώγου της στο X.
//
// Input, double XLEFT, XRITE, η αριστερή και η δεξιά
// ακραία σημεία του διαστήματος.
//
*/

Phi::Phi() {};

void Phi::phi(const int il, const double x, double* phii, double* phiix, const double xleft, const double xrite)


{
    if (xleft <= x && x <= xrite)
    {
        if (il == 1)
        {
            *phii = (xrite - x) / (xrite - xleft);
            *phiix = -1.0 / (xrite - xleft);
        }//if

        else
        {
            *phii = (x - xleft) / (xrite - xleft);
            *phiix = 1.0 / (xrite - xleft);
        }//else

    }//if

    //
    //  Αν βρίσκεται εκτός απλα το θέτουμε 0
    //

    else
    {
        *phii = 0.0;
        *phiix = 0.0;
    }//else


}
