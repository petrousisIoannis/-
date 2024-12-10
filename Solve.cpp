#include "Solve.h"
#include<iostream>

/*
Επιλύει ένα σύστημα τριγωνικών πινάκων της μορφής A*x = f.

// Input/Output, double ADIAG(NU), ALEFT(NU), ARITE(NU).
// Στο Input, τα ADIAG, ALEFT και ARITE περιέχουν τη διαγώνιο,
// τις αριστερές και τις δεξιές καταχωρήσεις των εξισώσεων.
// Στo Output, οι ADIAG και ARITE έχουν αλλάξει με τη σειρά
// για τον υπολογισμό της λύσης.
// Σημειώστε ότι για την πρώτη εξίσωση, δεν υπάρχει ALEFT
// και για την τελευταία, δεν υπάρχει συντελεστής ARITE.
// Έτσι, δεν υπάρχει ανάγκη να αποθηκεύσετε μια τιμή στην ALEFT(1), ούτε
// στο ARITE(NU).
//
// Input/Output, double F(NU).
// Στo Input, η F περιέχει τη δεξιά πλευρά της γραμμικής
// προς επίλυση.
// Στo Output, η F περιέχει τη λύση του γραμμικού συστήματος.
//
// Input, int NU, ο αριθμός των εξισώσεων προς επίλυση.
//
*/
Solve::Solve() {};

void Solve::solve(double adiag[], double aleft[], double arite[], double f[], const int nu)
{
  

    //
    //  Εκτελείται απαλοιφή Gauss στο σύστημα και αποθηκεύει για την αντίστροφη επίλυση.
    // 
    //

    arite[0] = arite[0] / adiag[0];

    for (int i = 1; i < nu - 1; i++)
    {
        adiag[i] = adiag[i] - aleft[i] * arite[i - 1];
        arite[i] = arite[i] / adiag[i];
            
    }//for

    adiag[nu - 1] = adiag[nu - 1] - aleft[nu - 1] * arite[nu - 2];
        
    //
    //  Πραγματοποιούνται τα ίδια βήματα απαλοιφής για το F που έγιναν για το
    //  πίνακα.
    //

    f[0] = f[0] / adiag[0];

    for (int i = 1; i < nu; i++)
    {
        f[i] = (f[i] - aleft[i] * f[i - 1]) / adiag[i];
          
    }//for

    //
    //  τώρα εκτελούνται τα βήματα της αντικατάστασης προς τα πίσω.
    //

    for (int i = nu - 2; 0 <= i; i--)
    {
        f[i] = f[i] - arite[i] * f[i + 1];
            
    }//for
    
    
}
