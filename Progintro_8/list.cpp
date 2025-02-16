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
    // Update branch: if k is within the current list, update the kth node.
    if (k >= 1 && k <= length) {
        Node *temp = head;
        // Traverse until the kth node (1-based indexing)
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        temp->value = x;
    }
    // Append branch: if k equals length+1, append a new node.
    else if (k == length + 1) {
        Node *newNode = new Node(x);
        newNode->next = nullptr;
        if (empty()) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        length++;
    }
    // No other case occurs as k is always valid by problem statement.
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
    
int main(){
    int N, X, K;
    scanf("%d", &N); // Read number of insertions.
    list L;
    for (int i = 0; i < N; i++){
        scanf("%d %d", &K, &X);
        L.add(K, X);
    }
    int M;
    scanf("%d", &M); // Read number of deletions.
    for (int i = 0; i < M; i++){
        scanf("%d", &K);
        L.remove(K);
    }
    scanf("%d", &K); // Read query position.
    printf("%d %d\n", L.size(), L.get(K));
    return 0;
}
