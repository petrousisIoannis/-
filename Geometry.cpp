﻿#include "Geometry.h"
#include <iostream>

using namespace std;

/*//Καθορίζει πως πρέπει να χωριστεί το σύστημα.

//Output, διπλό H(NSUB)
// H(I) είναι το μήκος του υποδιαστήματος I. Αυτός ο κώδικας χρησιμοποιεί
// ίσες αποστάσεις για όλα τα υποδιαστήματα.
//
// Input, int IBC.
// Το IBC δηλώνει ποιες είναι οι οριακές συνθήκες.
// 1, στο αριστερό ακραίο σημείο, το U έχει την τιμή UL,
// στο δεξιό ακραίο σημείο, το U' έχει την τιμή UR.
// 2, στο αριστερό ακραίο σημείο, το U' έχει την τιμή UL,
// στο δεξιό ακραίο σημείο, το U έχει την τιμή UR.
// 3, στο αριστερό ακραίο σημείο, το U έχει την τιμή UL,
// και στο δεξιό ακραίο σημείο, το U έχει την τιμή UR.
// 4, στο αριστερό ακραίο σημείο, το U' έχει την τιμή UL,
// στο δεξιό ακραίο σημείο το U' έχει την τιμή UR.
//
// Output, int INDX[NSUB+1].
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
// Input, int NL.
// Ο αριθμός των συναρτήσεων βάσης που χρησιμοποιούνται σε μια ενιαία
// υποδιάστημα. (NL-1) είναι ο βαθμός των πολυωνύμων.
// που χρησιμοποιούνται. Για αυτόν τον κώδικα, ο NL είναι σταθερός στο 2, που σημαίνει ότι
// χρησιμοποιούνται ως βάση γραμμικές συναρτήσεις κατά τεμάχια.
//
// Output, int NODE[NL*NSUB].
// Για κάθε υποδιάστημα I:
// NODE[0+I*2] είναι ο αριθμός του αριστερού κόμβου, και
// NODE[1+I*2] είναι ο αριθμός του δεξιού κόμβου.
//
// Input, int NSUB.
// Ο αριθμός των υποδιαστημάτων στα οποία χωρίζεται το διάστημα [XL,XR].
//
// Output, int NU.
// NU είναι ο αριθμός των αγνώστων στο γραμμικό σύστημα.
// Ανάλογα με την τιμή του IBC, θα υπάρχει NSUB-1,
// NSUB, ή NSUB+1 άγνωστες τιμές, οι οποίες είναι οι συντελεστές
// των συναρτήσεων βάσης.
//
// Input, double XL.
// XL είναι το αριστερό ακραίο σημείο του διαστήματος στο οποίο η
// επιλύεται η διαφορική εξίσωση.
//
// Output, double XN(0:NSUB).
// XN(I) είναι η θέση του Ι-οστού κόμβου. Το XN(0) είναι το XL,
// και XN(NSUB) είναι XR.
//
// Output, double XQUAD(NSUB)
// XQUAD(I) είναι η θέση του μοναδικού τετραγωνικού σημείου.
// στο διάστημα I.
//
// Input, double XR.
// XR είναι το δεξιό ακραίο σημείο του διαστήματος στο οποίο η
// επιλύεται η διαφορική εξίσωση.
//*/


	
Geometry::Geometry() {};


void Geometry::partion(double part[], const double xl, const double xr, double h[], double xquad[], const int nsub, const int ibc)
{
	// Δημιουργούμε την διαμέριση
	// Dhmiourgoume diamerish
	for (int i = 0; i <= nsub; i++)
	{
		part[i] = ((double)(nsub - i) * xl + (double)i * xr) / (double)(nsub); // i*(b-a)/nsub.
		
	}//for


	// Μήκος κάθε υποδιαστήματος.
	// Dhmiourgoume diamerish
	for (int i = 0; i < nsub; i++)
	{
		h[i] = part[i + 1] - part[i];
		
		
	}//for

	// Θέτουμε τα τετραγωνικά σημεία όπου το κάθε ένα είναι το μισό της διαμέρισης
	// thetoume ta quadrature shmeia opou to kathe ena einai to miso ths diamerishs 
	for (int i = 0; i < nsub; i++)
	{
		xquad[i] = 0.5 * (part[i] + part[i + 1]);
	
	}//for

	return;
}




void Geometry::node(int* nu, int node[], int indx[], const int nsub, const int ibc)
{
	int i;
	*nu = 0;

	for (i = 0; i < nsub; i++)
	{
		node[0 + i * 2] = i;		// node[0] = 0, node[2] = 1 
		node[1 + i * 2] = i + 1;	// node[1] = 1, node[3] = 2
		
	}//for

	//
	// Ξεκινάμε με τον κόμβο 0 για να δούμε αν υπάρχει άγωνστος. 
	// αν υπάρχει του δίνουμε μια τιμή

	//
	//	diaxeirish prwtou komvou(node)
	//

	i = 0;

	if (ibc == 1 || ibc == 3)
	{
		indx[i] = -1;
	
	}//if

	else
	{
		*nu = *nu + 1; 
		indx[i] = *nu; // indx[1] = 1, indx[2] = 2
		
	}//else

	//
	//	Diaxeirish twn komvwn(node) 1 ews nSubintervals - 1(arithmou ypodiasthamtwn - 1)
	//
	
	for (i = 1; i < nsub; i++)
	{
		*nu = *nu + 1;		// nu = 1, nu = 2, ... 
		indx[i] = *nu;		// indx[1] = 1, indx[2] = 2
		
	}//for

	//
	//	Diaxeirish tou teleutaiou komvou(node)
	//

	i = nsub;

	if (ibc == 2 || ibc == 3)
	{
		indx[i] = -1;
		
	}//if

	else
	{
		*nu = *nu + 1;
		indx[i] = *nu;
		
	}//else


}


