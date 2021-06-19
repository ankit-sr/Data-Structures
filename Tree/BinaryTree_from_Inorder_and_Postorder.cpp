#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		
		Node(int data){
			this->data = data;
			this->left = this->right = NULL;
		}
};

Node *createBinary_from_inorder_postorder(int[], int[], int, int);
int search(int[], int, int, int);
void printPostorder(Node*);

int main(){
	int inorder[] = {2,5,7,10,15,20,25};
	int postorder[] = {2,7,5,15,25,20,10};
	int length = sizeof(postorder)/sizeof(postorder[0]);
	Node *root = createBinary_from_inorder_postorder(inorder, postorder, 0, length-1);
	
	cout<<"\nPostorder traversal of created binary tree is : ";
	printPostorder(root);
}

Node *createBinary_from_inorder_postorder(int inorder[], int postorder[], int start, int end)
{
	int postIndex = end;
	
	if(start>end){
		return NULL;
	}	
	
	Node *newNode = new Node(postIndex--);
	
	if(start == end){
		return newNode;
	}
	
	int inIndex = search(inorder, start, end, newNode->data);
	
	newNode->right = createBinary_from_inorder_postorder(inorder, postorder, inIndex+1, end);
	newNode->left = createBinary_from_inorder_postorder(inorder, postorder, start, inIndex-1);
}

int search(int inorder[], int start, int end, int data){
	for(int i=start; i<=end; i++){
		if(inorder[i] == data)
			return i;
	}
}

void printPostorder(Node *root){
	if(root!=NULL){
		printPostorder(root->left);
		printPostorder(root->right);
		cout<<root->data<<" ";
	}
}
