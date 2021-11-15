  //Author: Luis Alvear
//ID: 0332145
//Chapter 4 tree

#include<iostream>
using namespace std;

struct node //Struct
{
	int data; //Holds data
	node* left; //Creates a pointer called left
	node* right; //Creates a pointer called right
};

//Function prototypes
void post(node*); //Holds funcion postorder
void pre(node*); //Holds function preorder
void inorder(node*);  //Holds fucntion inorder
node* create(int data); //Holds the function that creates the nodes
void insert(int, node*&); //Hols the function that inserts the nodes
void deletion(int, node*&); //Holds the function that deletes the nodes

int main() //Main
{
	int x; //Holds x, which is going to be used for the insertion and deletion node
	int choice; //Holds choice, used to choose a function of the program
	node* t; //Holds temp

	//Creates the root and assigns a value to it
	node* root= create(12); 
	root->left = create(8); 
	root->right = create(15);
	root->left->left = create(6);
	root->right->right = create(16);
	root->left->right = create(10);
	root->right->left = create(14);
	root->left->left->left = create(3);
	root->left->left->right = create(7);
	root->left->right->left = create(9);

	 
	do { //Do while loop
		//Displays menu
	cout <<"1. Display preorder, postorder and inorder of the tree: " << endl;
	cout << "2. Insert node: " << endl;
	cout << "3. Delete node: " << endl;
	cout << "4. Quit" << endl;
	cin >> choice; //User enters choice

		if (choice == 1) //When choice is equal to 1
		{
			//Displays the postorder, preorder and inorder
			cout << "Postorder: ";
			post(root); //Calls the function
			cout << endl;
			cout << "Preorder: ";
			pre(root); //Calls the preorder function
			cout << endl;
			cout << "Inorder: ";
			inorder(root); //Calls the inorder function 
			cout << endl;
		}
		if (choice==2) //When choice is equal to 2
		{
			cout << "Enter a value to insert: " << endl;
			cin >> x; //User enters the node to insert
			insert(x, *&root); //It calls the function
			cout << endl;
		}
		if (choice == 3) //When choice is equal to three
		{
			cout << "Enter a value to delete: " << endl;
			cin >> x; //The user enters the value that he wants to delete
			deletion(x, *&root); //Calls the delete function
		}
	} while (choice != 4);

}

node* create(int data) //Function to create the node
{
	node* n = new node; //Holds n and creates the new node
	n->data = data; //Points at data
	n->left = NULL; //Equals left to null
	n->right = NULL; //Equals right to null
	return n; //Returns n 

}
void post(node* t) //Function that holds the postoder
{
	if (t != NULL) //When t is not equal to null
	{
		post(t->left); 
		post(t->right);
		cout << t->data<<" "; //Displays the order (visits)
	}
}

void pre(node* t) //Function that holds the preorder
{
	if (t != NULL)
	{
		cout << t->data << " "; //Prints the preorder
		pre(t->left);
		pre(t->right);
		
	}
}

void inorder(node* t) //Function that holds the inorder
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->data << " "; //PRints the inorder
		inorder(t->right);
	}
}

void insert(int x, node*& t) //Function tht inserts the nodes
{
	
	if (t == nullptr) //When t is equal to null
	{
		t = new node{ x,nullptr,nullptr }; //Creates a new node
	}
	else if (x < t->data)
		insert(x, t->left); //Inserts to the left
	else if (t->data < x)
		insert(x, t->right); //Inserts on the right
	else; //duplicate

}

node* findmin(node* t)  //FUnction that finds the minimum value
{
	if (t == nullptr) //If t is equal to null
	{
		return nullptr; //Returns null
	}
	if (t->left == nullptr); //When the left node is equal to null
	return t; //Returns t
	return findmin(t->left); //Returns the function (recursive)

}
void deletion(int x, node*& t) //Deletion function
{
	if (t == nullptr) //Retutns when t is equal to null
		return;
	if (x < t->data)
		deletion(x, t->left); 
	else if (t->data < x)
		deletion(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // when it has 2 children
	{
		t->data = findmin(t->right)->data; 
		deletion(t->data, t->right); //Calls the function
	}
	else
	{
		node* oldnode = t; //Creates another variable which is equal to t
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldnode; //Deletes the node
	}
	
}