#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int value;      // The value of the node.
    Node *next;     // Pointer to the next node.
    Node(int v) : value(v), next(nullptr) {} // Constructor using initializer list.
};

class list {
public:
    list();                    // Constructs an empty list.
    bool empty();              // Checks if the list is empty.
    int size();                // Returns the current length of the list.
    // If 1 <= k <= length, updates the kth node's value;
    // if k == length+1, appends a new node with x.
    void add(int k, int x);
    int get(int k);            // Returns the value of the kth element.
    void remove(int k);        // Deletes the kth element from the list.
    int searchMF (int x);
    
private:
    Node *head;                // Points to the first node.
    int length;                // Number of elements in the list.
};

list::list() : head(nullptr), length(0) { }

bool list::empty() {
    return (length == 0);
}

int list::size() {
    return length;
}

void list::add(int k, int x) {
    Node *newNode = new Node(x);
    if (k == 1){
        newNode->next = head; // we do this because we want to insert the new node at the beginning of the list.
        head = newNode; // update the head pointer to point to the new node.
        length++;
        return;
    }else {
        Node *temp = head;
        for (int i=1; i<k-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    length++;
}

int list::get(int k) {
    Node *temp = head;
    // Traverse to the kth node.
    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }
    return temp->value;
}

void list::remove(int k) {
    if (k == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        length--;
        return;
    }
    Node *temp = head;
    // Traverse to the (k-1)th node.
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    length--;
}
    
int list::searchMF(int x){ //this returns the position in the list of element x
    Node *temp = head; 
    int pos = 1;
    while (temp != nullptr){
        if (temp->value == x){
            //we now need to move this to the head of the list
            add(1, x);
            remove(pos+1);
            return pos;
        }
        temp = temp->next;
        pos++;
    }

    return 0;
}

int main(){
    int N, X, K;
    int sum = 0;
    scanf("%d", &N); // Read number of insertions.
    list L;
    for (int i = 0; i < N; i++){
        scanf("%d %d", &K, &X);
        L.add(K, X);
    }
    int M;
    scanf("%d", &M); // Read number of searches
    for (int i = 0; i < M; i++){
        scanf("%d", &K);
        sum += L.searchMF(K); //sum the position of the element K in the list
    }
    scanf("%d", &K); // Read query position.
    printf("%d\n", sum);
    return 0;
}
