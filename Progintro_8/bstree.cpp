#include <iostream>
#include <cstdio>
using namespace std;

/*
first line we read the number N of integers we will insert in the BST
second line we read the integers to insert (they are distinct)
third line we read the number M of searches we will perform in the bst
fourth line we read the integers to search in the BST
*/

/*
first we print the height of the BST
then we print min and max value of the BST with a space inbetween them
then we print M numbers seperated per two with a space which will be the results of the search in the BST
then we print the inorder traversal of the BST with a space between the numbers and the word "end" at the end
then we print the preorder traversal of the BST with a space between the numbers and the word "end" at the end
then we print the postorder traversal of the BST with a space between the numbers and the word "end" at the end
*/

struct BSTree {
    int value;
    BSTree *left; // pointer to the left child
    BSTree *right; // pointer to the right child
    BSTree(int x) : value(x), left(nullptr), right(nullptr) {} // constructor for the BSTree
    //what the constructor does is that it initializes the value of the node to x and the left and right children to nullptr
};

//this is a data structure for a binary search tree (BST) that stores integers
class bstree {
    public: 
      bstree    ();       /* we construct an empty BST */ 
      int  height    ();       /* returns the height of the bst, an empty BST has a height of 0 */ 
      void insert    (int x);  /* inserts number x in the bst */
      int  search    (int x);  /* searches for the number x in the bst and returns the level in which it belongs,
                                if it doesn't exist, it is 0, if it is the root it is 1 */
      int  min       ();       /* returns the minimum element of the BST */
      int  max       ();       /* returns the max element of the bst */
      void inorder   ();       /* prints the BST elements in inorder traversal */
      void preorder  ();       /* prints the BST elements in preorder traversal */
      void postorder ();       /* prints the BST elements in postorder traversal */

    private:
        BSTree *root; //pointer to the root of the BST

        //helpers : these are functions that are used to help the main functions to work
        int heightHelper(BSTree* node); //this function is used to calculate the height of the BST
        void insertHelper(BSTree*& node, int x); //this function is used to insert a number x in the BST
        int searchHelper(BSTree* node, int x, int level); //this function is used to search for a number x in the BST
        //the level parameter is used to keep track of the level of the node we are currently at
        BSTree* findMin(BSTree* node); //this function is used to find the minimum element of the BST
        BSTree* findMax(BSTree* node); //this function is used to find the maximum element of the BST
        void inorderHelper(BSTree* node); //this function is used to print the BST elements in inorder traversal
        void preorderHelper(BSTree* node); //this function is used to print the BST elements in preorder traversal
        void postorderHelper(BSTree* node); //this function is used to print the BST elements in postorder traversal
    };

    bstree::bstree(){
        root = nullptr; //initialize the root to nullptr
    }

    int bstree::height(){
        return heightHelper(root); //call the helper function to calculate the height of the BST by calculating at the root
    }

    int bstree::heightHelper(BSTree* node){
        if(node == nullptr){
            return 0; //if the node is nullptr, then the height is 0
        }
        int lh = heightHelper(node->left); //calculate the height of the left subtree
        int rh = heightHelper(node->right); //calculate the height of the right subtree
        return 1 + (lh > rh ? lh : rh); //return the height of the BST lh > rh ? lh : rh means if lh is greater than rh return lh else return rh   
    }

    void bstree::insert(int x){
        insertHelper(root, x); //call the helper function to insert the number x in the BST
    }

    void bstree::insertHelper(BSTree*& node, int x){
        if (node == nullptr){
            node = new BSTree(x); //if the node is nullptr, then we create a new node with the value x
            //when is the node==nullptr true? when we reach a leaf node, then we create a new node with the value x
            return;
        }
        if (x < node->value){
            insertHelper(node->left, x); //if x is less than the value of the node, then we go to the left subtree
        } else {
            insertHelper(node->right, x); //if x is greater than the value of the node, then we go to the right subtree
        }
    }

    int bstree::search(int x){
        return searchHelper(root, x, 1); //call the helper function to search for the number x in the BST
    }

    int bstree::searchHelper(BSTree* node, int x, int level){
        if (node == nullptr){
            return 0; //if the node is nullptr, then the number x doesn't exist in the BST
        }
        if (x == node->value){
            return level; //if the number x is equal to the value of the node, then we return the level of the node
        }
        if (x < node->value){
            return searchHelper(node->left, x, level + 1); //if x is less than the value of the node, then we go to the left subtree
        } else {
            return searchHelper(node->right, x, level + 1); //if x is greater than the value of the node, then we go to the right subtree
        } 
    }

    int bstree::min(){
        BSTree* minNode = findMin(root); //find the minimum element of the BST, we start by looking at the root
        return minNode->value; //return the value of the minimum element
    }

    BSTree* bstree::findMin(BSTree* node){
        if (node == nullptr){
            return nullptr; //if the node is nullptr, then the minimum element is nullptr
        }
        while (node->left != nullptr){
            node = node->left; //keep going to the left subtree until we reach the leaf node
        }
        return node; //return the minimum element
    }

    int bstree::max(){
        BSTree* maxNode = findMax(root); //find the maximum element of the BST, we start by looking at the root
        return maxNode->value; //return the value of the maximum element
    }

    BSTree* bstree::findMax(BSTree* node){
        if (node == nullptr){
            return nullptr; //if the node is nullptr, then the maximum element is nullptr
        }
        while (node->right != nullptr){
            node = node->right; //keep going to the right subtree until we reach the leaf node
        }
        return node; //return the maximum element
    }

    void bstree::inorder(){
        inorderHelper(root); //print the BST elements in inorder traversal
        cout << "end" << endl; //print the word "end" at the end
    }

    void bstree::inorderHelper(BSTree* node){
        if (node == nullptr){
            return; //if the node is nullptr, then we return
        }
        inorderHelper(node->left); //print the left subtree
        cout << node->value << " "; //print the value of the node
        inorderHelper(node->right); //print the right subtree
    }

    void bstree::preorder(){
        preorderHelper(root); //print the BST elements in preorder traversal
        cout << "end" << endl; //print the word "end" at the end
    }

    void bstree::preorderHelper(BSTree* node){
        if (node == nullptr){
            return; //if the node is nullptr, then we return
        }
        cout<< node->value << " "; //print the value of the node
        preorderHelper(node->left); //print the left subtree
        preorderHelper(node->right); //print the right subtree
    }

    void bstree::postorder(){
        postorderHelper(root); //print the BST elements in postorder traversal
        cout << "end" << endl; //print the word "end" at the end
    }

    void bstree::postorderHelper(BSTree* node){
        if (node == nullptr){
            return; //if the node is nullptr, then we return
        }
        postorderHelper(node->left); //print the left subtree
        postorderHelper(node->right); //print the right subtree
        cout << node->value << " "; //print the value of the node
    }


    int main(){
        int N;
        scanf("%d", &N); //read the number N of integers we will insert in the BST
        bstree T;
        for (int i = 0; i < N; i++){
            int x;
            scanf("%d", &x); //read the integers to insert (they are distinct)
            T.insert(x); //insert the integers in the BST
        }

        // 1. print height of the BST
        printf("%d\n", T.height());

        // 2. print min and max value of the BST
        printf("%d %d\n", T.min(), T.max());

        int M;
        scanf("%d", &M); //read the number M of searches we will perform in the bst
        for (int i = 0; i < M; i++){
            int x;
            scanf("%d", &x); //read the integers to search in the BST
            printf("%d ", T.search(x)); //3. print the results of the search in the BST
        }
        printf("\n");

        // 4. print the inorder traversal of the BST
        T.inorder();

        // 5. print the preorder traversal of the BST
        T.preorder();

        // 6. print the postorder traversal of the BST
        T.postorder();

        return 0;
    }