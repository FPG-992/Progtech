#include <iostream>
using namespace std;

/*
we read a sequence of non zero integers from stdin
we check if it has as many positive as negative numbers and
at the same time we check if the negatives appear in the same sequence as the positives
per absolute value
*/


class queue {
    public:
           queue   ();       /* κατασκευαστής:  κατασκευάζει μία κενή ουρά */
      bool empty   ();       /* ελέγχει αν η ουρά είναι κενή */
      void enqueue (int x);  /* εισάγει ένα στοιχείο στην ουρά */
      int  dequeue ();       /* αφαιρεί ένα στοιχείο από μια μη κενή ουρά */
      int  peek    ();       /* επιστρέφει (χωρίς να αφαιρεί) το πρώτο στοιχείο μιας μη κενής ουράς */
    };
