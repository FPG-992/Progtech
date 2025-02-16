#include <iostream>
#include <cstdio>
using namespace std;

/*
we read a sequence of non zero integers from stdin
we check if it has as many positive as negative numbers and
at the same time we check if the negatives appear in the same sequence as the positives
per absolute value
*/

/*
we will use a connected list to build the data structure
*/

struct Node { // a node in the list
    int value; // the value of the node
    Node *next; // the next node in the list, NULL if this is the last node in the list.
    // *next is a pointer to a node which means that it can be NULL or point to a node 
    //(pointing to a node means that it contains the address of the node it points to)
    };
class Queue {
    public: //public means that the following methods can be accessed from outside the class
      //accessing from outside the class means that we can call these methods from the main function
      Queue   ();       /* constructs an empety queue */
      bool empty   ();       /* checks if queue is empty */
      void enqueue (int x);  /* adds an element in the queue */
      int  dequeue ();       /* removes an element from a non empty queue */
      int  peek    ();       /* returns without removing the element of a non empty queue */

    private: //private means that the following variables can only be accessed from within the class
      //which means that they can only be accessed from the methods of the class, not from the main function
      Node *head; //points to the first element of the queue (NULL if the queue is empty)
      Node *tail; //points to the last element of the queue (NULL if the queue is empty)
    };

Queue::Queue () { //this is the constructor for the class Queue
    head = nullptr;
    tail = nullptr;
 }

bool Queue::empty (){ //checks if queue is empty
  return head == nullptr; //if head is NULL then the queue is empty
}

void Queue::enqueue(int x){
  Node *newNode = new Node; //we create a new node in the heap memory 
  //(heap memory is used for dynamic memory allocation)
  newNode->value = x; //we set the value of the new node equal to x.
  newNode->next = nullptr; //since the new node is the last, it should point to NULL.

  if(empty()){
    head = newNode; //if queue is empty then the new node is the first and last element of the queue
    tail = newNode;
  }else { //if the queue is not empty
    tail->next = newNode; //the last element should point to the new node of the queue
    tail = newNode; //the new node should now be the last element of the queue
  }
}

int Queue::dequeue(){ //removes an elemnt from a non empty queue
  if(empty()){
    exit(1); //if the queue is empty then we exit the program
  }
  int RetrievedValue = head->value; //we store the value of the first element of the queue in a variable
  Node *temp = head; //we create a node that points to the first element of the queue
  head = head->next; //the head should now point to the next element of the queue because 
  //we are removing the first element

  if(head == nullptr){ //if the queue is empty after removal then we should set tail to Null too
    tail = nullptr;
  }

  delete temp; //we delete the first element of the queue from the heap memory to avoid memory leaks
  return RetrievedValue; //we return the value of the first element of the queue
}

int Queue::peek(){ //we return the value of the first element without removing it 
  if (empty()){
    exit(1); //if the queue is empty then we exit the program
  }
  return head->value; //we return the value of the first element of the queue
}

int main(){
  Queue PositiveNumbers; //we create the queue for the positive numbers
  Queue NegativeNumbers; //we create the queue for the negative numbers
  int X; //we create a variable to store the input values
  int PositiveCounter = 0; //we create a variable to count the number of positive numbers
  int NegativeCounter = 0; //we create a variable to count the number of negative numbers

  while (scanf("%d", &X) == 1 && X!=0){
    if (X > 0){ //X is positive and we add it to the PositiveNumbers Queue
      PositiveNumbers.enqueue(X);
      PositiveCounter++;
    }
    else{ //X is negative and we add its absolute Value to the NegativeNumbers Queue
      NegativeNumbers.enqueue(abs(X));
      NegativeCounter++;
    }
  }

  if (PositiveCounter != NegativeCounter){
    cout<<"no"<<endl;
    return 0;
  }

  while(!PositiveNumbers.empty()){
    if (PositiveNumbers.peek() != NegativeNumbers.peek()){
      cout<<"no"<<endl;
      return 0;
    } else {
      PositiveNumbers.dequeue();
      NegativeNumbers.dequeue();
    }
  }

  cout<<"yes"<<endl;

  return 0;
}