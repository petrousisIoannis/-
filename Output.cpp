#include "Output.h"
#include <iostream>
#include <iomanip>

/* Εκτυπώνει την υπολογισμένη λύση. 
 
// Input, double F(NU).
// ASSEMBLE αποθηκεύει στο F τη δεξιά πλευρά της γραμμικής
// εξισώσεων.
// SOLVE αντικαθιστά αυτές τις τιμές της F με τη λύση της
// γραμμικών εξισώσεων.
//
// Input, int IBC.
// Η IBC δηλώνει ποιες είναι οι οριακές συνθήκες.
// 1, στο αριστερό ακραίο σημείο, το U έχει την τιμή UL,
// στο δεξιό ακραίο σημείο, το U' έχει την τιμή UR.
// 2, στο αριστερό ακραίο σημείο, το U' έχει την τιμή UL,
// στο δεξιό ακραίο σημείο, το U έχει την τιμή UR.
// 3, στο αριστερό ακραίο σημείο, το U έχει την τιμή UL,
// και στο δεξιό ακραίο σημείο, το U έχει την τιμή UR.
// 4, στο αριστερό ακραίο σημείο, το U' έχει την τιμή UL,
// στο δεξιό ακραίο σημείο το U' έχει την τιμή UR.
//
// Input, int INDX[NSUB+1].
// Για έναν κόμβο I, INDX(I) είναι ο δείκτης του άγνωστου
// που σχετίζεται με τον κόμβο Ι.
// Αν INDX(I) είναι ίσο με -1, τότε δεν συνδέεται κανένας άγνωστος.
// με τον κόμβο, επειδή μια οριακή συνθήκη που καθορίζει το
// τιμή του U έχει εφαρμοστεί στον κόμβο.
// Οι άγνωστοι αριθμούνται αρχίζοντας από το 1.
// Εάν το IBC είναι 2 ή 4, τότε υπάρχει μια άγνωστη τιμή του U
// στον κόμβο 0, η οποία θα είναι ο άγνωστος αριθμός 1. Διαφορετικά,
// ο άγνωστος αριθμός 1 θα συσχετιστεί με τον κόμβο 1.
// Εάν το IBC είναι 1 ή 4, τότε υπάρχει μια άγνωστη τιμή του U
// στον κόμβο NSUB, η οποία θα είναι ο άγνωστος NSUB ή NSUB+1,
// ανάλογα με το αν υπήρχε άγνωστος στον κόμβο 0.
//
// Input, int NSUB.
// Ο αριθμός των υποδιαστημάτων στα οποία χωρίζεται το διάστημα [XL,XR].
//
// Input, int NU.
// NU είναι ο αριθμός των αγνώστων στο γραμμικό σύστημα.
// Ανάλογα με την τιμή του IBC, θα υπάρχει NSUB-1,
// NSUB, ή NSUB+1 άγνωστες τιμές, οι οποίες είναι οι συντελεστές
// των συναρτήσεων βάσης.
//
// Input, διπλό UL.
// Εάν το IBC είναι 1 ή 3, το UL είναι η τιμή που απαιτείται U
// να έχει στη θέση X = XL.
// Αν το IBC είναι 2 ή 4, το UL είναι η τιμή που πρέπει να έχει το U'.
// να έχει στη θέση X = XL.
//
// Input, διπλό UR.
// Εάν το IBC είναι 2 ή 3, UR είναι η τιμή που απαιτείται από το U
// να έχει στη θέση X = XR.
// Εάν το IBC είναι 1 ή 4, UR είναι η τιμή που απαιτείται να έχει η U'.
// να έχει στη θέση X = XR.
//
// Input, double XN(0:NSUB).
// XN(I) είναι η θέση του Ι-οστού κόμβου. Η XN(0) είναι η XL,
// και XN(NSUB) είναι XR.
//

*/


Output::Output() {};

void Output::output(double f[], int indx[], const int nu, const double ul, const double ur, double part[], const int nsub, const int ibc, double real[], double h[])
{
    Initialization init;


    for (int i = 0; i <= nsub; i++) {
        real[i] = init.setRealValue(part[i]);
        //std::cout << real[i] << std::endl;
    }

   //std::cout //<< " Index " << std::setw(14)
   //   << " Subinterval " << std::setw(14)
   //   << " Ap. Value " << std::setw(14)
   //   << " Real Value " << std::setw(14)
   //    << " Error " << std::setw(14) << "\n"; 

    double L2_error = 0.0;
    for (int i = 0; i <= nsub; i++)
    {
        //
        //  an eimaste ston prwto komvo(node) elegxoume tis oriakes synthikes(ibc)
        //

        if (i == 0)
        {
            if (ibc == 1 || ibc == 3)
            {
                u = ul;

            }//if2

            else
            {
                u = f[indx[i] - 1];

            }//else

        }//if1

        //
        //  an eimaste ston teleutaio komvo(node) elegxoume tis oriakes synthikes(ibc)
        //

        else if (i == nsub)
        {

            if (ibc == 2 || ibc == 3)
            {
                u = ur;

            }//if

            else
            {
                u = f[indx[i] - 1];

            }//else

        }//else if

        //
        //  Gia opoiodhpote allo komvo(node) apothikeuetai ston pinaka f
        //

        else
        {
            u = f[indx[i] - 1];

        }//else


        //std::cout << i
            //<< "  " << std::setw(8) << part[i]//<< std::endl;
            //<< "  " << std::setw(14) << u << std::endl;
          // << "  " << std::setw(14) << real[i] << std::endl;
            //<< "  " << std::setw(14) << abs(u - real[i]) << "\n";

    }        //L2 norm
    
    for (int i = 0; i < nsub-1; i++) 
    {
        double u_exact = real[i];                   //ακριβης λυση
        double diff = u_exact - f[i];              // διαφορα μεταξυ ακριβους και προσεγγιστικης
        L2_error += diff * diff * h[i];


        //std::cout << i << " : " << f[i] << std::endl;

    }//for

    //υπολογισμος της L2 νορμας
    L2_error = sqrt(L2_error);
    std::cout << "Gia arithmo ypodiasthmatwn: " << nsub << std::endl
       << "L2 norm: " << L2_error << std::endl;
    ////

    
    return;
}


void Output::printsDiagLinearSys(double adiag[], double aleft[], double arite[], double f[], const int nu)
{
    //std::cout << "\n";
   // std::cout << "Printout of tridiagonal linear system:\n";
   // std::cout << "\n";
    //std::cout << "Equation  ALEFT  ADIAG  ARITE  RHS\n";
    //std::cout << "\n";

    //for (int i = 0; i < nu; i++)
    //{
       // std::cout << "  " << std::setw(8) << i + 1
         //   << "  " << std::setw(14) << aleft[i]
         //   << "  " << std::setw(14) << adiag[i]
          //  << "  " << std::setw(14) << arite[i]
          //  << "  " << std::setw(14) << f[i] << "\n";
   // }//for
    
}
