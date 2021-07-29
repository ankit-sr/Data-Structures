/*
	Array is a linear data structure, which stores the elements in a contiguous memory locations.
	Arrays can be said as a list of similar types of elements i.e., an array can store the values
	with similar data type. 
	For example: if an array is of integer type, then it can store only integer varibles.

	Array can be of both predefined data types such as int, bool, etc. as well as user-defined
	data types such as structures, classes, etc.
	Operations performed on an array are:
		1. Insertion
		2. Traversal and Searching
		3. Updation
		4. Deletion
*/

// Implementaion
#include<iostream>
using namespace std;

void insert(int,int,int[]);
void display(int[]);
int search(int,int []);
inline void update(int,int,int[]);
void del(int,int[]);


int main()
{
	// Declaring an array of size 10
	int array[10];
	int n, m;

	// Initaililzing all the elements of array with 0.
	for(int i=0; i<10; i++)
	{
		array[i]=0;
	}

	cout<<"Please note that the maximum size of the array can be 10";

	// Asking user to perform various operations on Array.
	do
	{
		cout<<"\n1.Insert \n2.Display \n3.Search \n4.Update \n5.Delete \n6.Exit \nEnter your choice : ";
		cin>>n;
		switch(n)
		{
			case 1:
				cout<<"Enter data to insert :";
				cin>>n;
				cout<<"Enter the index number : ";
				cin>>m;
				insert(n,m,array);
				break;

			case 2:
				display(array);
				break;

			case 3:
				cout<<"Enter the element to search :";
				cin>>m;
				n = search(m,array);
				if(n == -1)
					cout<<"Element not found";
				else
					cout<<"Element founded at index "<<n;
				break;

			case 4:
				cout<<"Enter the data to update :";
				cin>>n;
				cout<<"Enter index : ";
				cin>>m;
				update(n,m,array);
				break;

			case 5:
				cout<<"Enter element to delete : ";
				cin>>m;
				del(m,array);
				break;

			case 6:
				exit(0);

			default:
				cout<<"Please enter a valid choice : ";
				break;
		}
	}while(1);

	return 0;	
}

// Method to insert elements in the array.
void insert(int x,int y,int array[])	//x-data   y-index
{
	// If no element is present in the specified index
	if(array[y]==0)
	{
		array[y]=x;
	}

	// If element is present, shift them with one index
	// to create space for the elemnt to be inserted at desired index.
	else
	{
		for(int i=19;i<y;i--)
		{
			array[i]=array[i-1];
		}
		array[y]=x;
	}
}

// Method to display all the elements of the array.
void display(int array[])
{
	cout<<"\nArray is :\n";
	for(int i=0;i<10;i++)
	{
		cout<<array[i]<<endl;
	}
}

// Method to search an element in the array
int search(int x,int array[])
{
	int i=0;
	while(i<10)
	{
		if(array[i]==x)
		{
			return i;
		}
		else
		{
			i++;
		}
	}
	return -1;
}

// This method updates an element at specifed index
// by replacing the previously stored element.
void update(int x,int y,int array[])
{
	array[y]=x;
}

// Method to delete the element from array.
void del(int x,int array[])
{
	// Search the element in the array
	int i = search(x, array);

	// If element is not found
	if(i == -1)
		cout<<"\nElement not present in the array";

	// If element is found, shift all the elements towards one index to left
	else
	{
		for (int j=i;j<10;j++)
			{
				array[j]=array[j+1];
			}
	}
}

