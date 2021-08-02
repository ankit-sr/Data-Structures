 #include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
    // The structure of each node of the binary tree.
        int data;
        BinaryTree *left;
        BinaryTree *right;
    public:

        BinaryTree(){}
    //Constructor to initialize pointers with NULL
        BinaryTree(int x)
        {
            data = x;
            left = right = NULL;
        }
        BinaryTree *create();
        int countLeaves(BinaryTree*);
};

//Recursion based create() method to implement binary tree.
BinaryTree* BinaryTree::create()
{
//Data to be added to the binary tree.
    int x; 
    
//Taking input from user
    cout << "\nEnter data (-1 for no node) : ";
    cin >> x;
    if (x == -1)
        return NULL;

//Creating a node for the inserted data.
	BinaryTree *newNode = new BinaryTree(x);
	
//Asking for left and right child of the node.
    cout << "\nFor left child of "<<x<<" : ";
    newNode->left = create();

    cout << "\nFor right child of "<<x <<" : " ;
	newNode->right = create();

    return newNode;
}

// Method to count the number of leaf nodes in binary tree
int BinaryTree::countLeaves(BinaryTree* root)
{
    // If the node is leaf node
    if(root->left == NULL && root->right == NULL)
        return 1;

    // For recursive calls, declare and initialize variables
    // with 0, to store the leaf nodes of subtree.   
    int leftleaves = 0, rightleaves = 0;
    
    // If node have a left child
    if(root->left!=NULL)   
        leftleaves = countLeaves(root->left);
    
    // If node have a right child
    if(root->right!=NULL)
        rightleaves = countLeaves(root->right);
    
    return leftleaves+rightleaves;
}

int main()
{
//Creating the root pointer for the binary tree.
    BinaryTree *root = NULL;
    BinaryTree node;

//Calling the create method and storing the address of the root node into root pointer declared above.    
    root = node.create();
    
    cout<<"Tree created successfully : ";

    cout<<"\nNumber of Leaf Nodes in tree :"<<node.countLeaves(root);
    
    return 0;
}