#include<iostream>
#include"Geometry.h"
#include"Assemble.h"
#include"Solve.h"
#include"Output.h"
#include <chrono>
using namespace std::chrono;



#define nSubintervals              100            // Ο αριθμός υποδιαστημάτων που χωρίζουν το διάστημα [leftEndPoint,rightEndPoint]. 
#define typeOfBasisFunctions        2                   // Ο αριθμός συναρτήσεων βάσης που χρησιμοποιούνται (είναι σταθερό στον κώδικα).
#define nQuadraturePoints           1                   // Αριθμός τετραγωνικών σημείων (είναι σταθερό στον κώδικα).
#define leftEndPoint                0                   // Το μικρότερο άκρο της συνάρτησης.
#define rightEndPoint               1                   // Το μεγαλύτερο άκρο της συνάρτησης.
#define valueInLeftEndPoint         0                   // Η τιμή της συνάρτησης στο αριστερό άκρο. 
#define valueInRightEndPoint        0                   // Η τιμή της συνάρτησης στο δεξί άκρο.
#define typeOfBoundaryConditions    3                   // Είδος οριακών συνθηκών (Υπάρχουν 4 είδη στον κώδικα για λεπτομέρειες στην claas Geometry γραμμή 12). 



int main()
{
    auto start = high_resolution_clock::now();

    double adiag[nSubintervals + 1];                    // Ο πίνακας που περιέχει τη διαγώνιο του Α.
    double aleft[nSubintervals + 1];                    // Ο πίνακας που περιέχει την τιμη αριστερά της διαγωνίου του Α.
    double arite[nSubintervals + 1];                    // Ο πίνακας που περιέχει την τιμη δεξιά της διαγωνίου του Α.
    double f[nSubintervals + 1];                        // Ο πίνακας αποτελεσμάτων της προσεγγιστική λύσης.
    double h[nSubintervals + 1];                        // Ο πίνακας με τις διαμερίσεις. 
    double part[nSubintervals + 1];                     // Ο πίνακαμε τα αποτελέσματα σε κάθε διαμέριση.
    double real[nSubintervals + 1];                     // Ο πίνακας των πραγματικών τιμών της συνάρτησης.
    double xquad[nSubintervals];                        // Ο πίανκας με τα τετραγωνικά σημεία.                       
    int indx[nSubintervals + 1];                        // Ο πίνακας με το πλήθος των αγνώστων. (Περισσότερες λεπτομέρειες στην class Geometry γραμμή 23)
    int node[typeOfBasisFunctions * nSubintervals];     // O πίνακας με τους αριθμούς για κάθε υποδιάστημα I αριστερά και δεξιά  (περισσότερες λεπτομέρειες στη class Geometry γραμμή 43 και η υλοποίηση 120)
    int nu;                                             // Το πλήθος των αγνώστων (Περισσότερες λεπτομέρειες στην class Geometry γραμμή 51) 
         
   
   


    Initialization init;

    Geometry parti;
    parti.partion(part, leftEndPoint, rightEndPoint, h, xquad, nSubintervals, typeOfBoundaryConditions);
    parti.node(&nu, node, indx, nSubintervals, typeOfBoundaryConditions);


    Assemble allTogether;
    allTogether.assemble(f, arite, aleft, adiag, h, indx, typeOfBasisFunctions, node, nu, valueInLeftEndPoint, valueInRightEndPoint, part, xquad, nQuadraturePoints, nSubintervals);
    
   
    Solve solver;
    solver.solve(adiag, aleft, arite, f, nu);

   
    Output prints;
    prints.output(f, indx, nu, valueInLeftEndPoint, valueInRightEndPoint, part, nSubintervals, typeOfBasisFunctions, real, h);
    prints.printsDiagLinearSys(adiag, aleft, arite, f, nu);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

   std::cout << duration.count();


  
}


