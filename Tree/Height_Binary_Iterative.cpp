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
        int Height(BinaryTree*);

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

// Method to iteratively find the height of the tree.
int BinaryTree::Height(BinaryTree *root){

    // If tree contains no node.
    if(root == NULL)
        return 0;

    // Create a queue to insert the nodes of each level in it
    queue<BinaryTree*> queue;

    // Initially insert the root of the tree.
    queue.push(root);

    // and initialize height with 0
    int height = 0;

    while(1){

        // nodeCount is the number of nodes at any level of tree
        // which is equal to the size of the queue at that instant.
        int nodeCount = queue.size();

        // If queue is empty, then  we have reached the end of the tree.
        if(nodeCount == 0)
            return height;
        
        height++;

        // Otherwise, remove the element from 
        while(nodeCount>0){

            BinaryTree *node = queue.front();
            queue.pop();

            if(node->left != NULL)
                queue.push(node->left);

            if(node->right != NULL)
                queue.push(root->right);

            nodeCount--;
        }
            

    }
    

}

int main()
{
//Creating the root pointer for the binary tree.
    BinaryTree *root = NULL;
    BinaryTree node;

//Calling the create method and storing the address of the root node into root pointer declared above.    
    root = node.create();
    
    cout<<"Tree created successfully : ";

    cout<<"\nHeight of the tree is : "<<node.Height(root);
    
    return 0;
}