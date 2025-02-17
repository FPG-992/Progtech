#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct BSTNode {
    int value;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

class bstree {
public:
    bstree();
    int height();
    void insert(int x);
    int search(int x);
    int min();
    int max();
    void inorder();
    void preorder();
    void postorder();

private:
    BSTNode *root;

    // Helpers
    int heightHelper(BSTNode* node);
    void insertHelper(BSTNode*& node, int x);
    int searchHelper(BSTNode* node, int x, int level);
    BSTNode* findMin(BSTNode* node);
    BSTNode* findMax(BSTNode* node);
    void inorderHelper(BSTNode* node);
    void preorderHelper(BSTNode* node);
    void postorderHelper(BSTNode* node);
};

// Constructor: empty BST
bstree::bstree() : root(nullptr) {}

// Height (empty = 0)
int bstree::height() {
    return heightHelper(root);
}

int bstree::heightHelper(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int lh = heightHelper(node->left);
    int rh = heightHelper(node->right);
    return 1 + (lh > rh ? lh : rh);
}

// Insert
void bstree::insert(int x) {
    insertHelper(root, x);
}

void bstree::insertHelper(BSTNode*& node, int x) {
    if (node == nullptr) {
        node = new BSTNode(x);
        return;
    }
    if (x < node->value) {
        insertHelper(node->left, x);
    } else {
        // assume x > node->value for distinct integers
        insertHelper(node->right, x);
    }
}

// Search
int bstree::search(int x) {
    return searchHelper(root, x, 1);
}

int bstree::searchHelper(BSTNode* node, int x, int level) {
    if (node == nullptr) {
        return 0; // not found
    }
    if (node->value == x) {
        return level;
    }
    if (x < node->value) {
        return searchHelper(node->left, x, level + 1);
    } else {
        return searchHelper(node->right, x, level + 1);
    }
}

// Min
int bstree::min() {
    if (root == nullptr) {
        // Handle error or assume input guaranteed non-empty
        fprintf(stderr, "Error: calling min() on empty BST\n");
        exit(1);
    }
    BSTNode* mn = findMin(root);
    return mn->value;
}

BSTNode* bstree::findMin(BSTNode* node) {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Max
int bstree::max() {
    if (root == nullptr) {
        fprintf(stderr, "Error: calling max() on empty BST\n");
        exit(1);
    }
    BSTNode* mx = findMax(root);
    return mx->value;
}

BSTNode* bstree::findMax(BSTNode* node) {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// Inorder
void bstree::inorder() {
    inorderHelper(root);
}

void bstree::inorderHelper(BSTNode* node) {
    if (node == nullptr) return;
    inorderHelper(node->left);
    cout << node->value << " ";
    inorderHelper(node->right);
}

// Preorder
void bstree::preorder() {
    preorderHelper(root);
}

void bstree::preorderHelper(BSTNode* node) {
    if (node == nullptr) return;
    cout << node->value << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
}

// Postorder
void bstree::postorder() {
    postorderHelper(root);
}

void bstree::postorderHelper(BSTNode* node) {
    if (node == nullptr) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << node->value << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  // read how many numbers to insert
    bstree T;

    // Insert N distinct integers
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        T.insert(x);
    }

    // Height of the created BST
    int h = T.height();

    // min and max
    int mn = T.min();
    int mx = T.max();

    // number of searches
    int M;
    cin >> M;
    vector<int> results(M);

    // Perform M searches
    for(int i = 0; i < M; i++){
        int x;
        cin >> x;
        results[i] = T.search(x);  // store the result
    }

    // 1. print height
    cout << h << "\n";

    // 2. print min and max
    cout << mn << " " << mx << "\n";

    // 3. print the M results
    // The example shows them in a single line separated by spaces
    // e.g., "4 1 0" for M=3
    for(int i = 0; i < M; i++){
        cout << results[i];
        if(i < M - 1) cout << " ";
    }
    cout << "\n";

    // 4. Inorder + "end"
    T.inorder();
    cout << "end\n";

    // 5. Preorder + "end"
    T.preorder();
    cout << "end\n";

    // 6. Postorder + "end"
    T.postorder();
    cout << "end\n";

    return 0;
}
