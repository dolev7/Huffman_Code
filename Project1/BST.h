#pragma once
namespace Hofman
{
	struct node 
	{
		int _frequency;
		char _letter;
		node* left;
		node* right;
	};
	class BST
	{
	private:
		
		node* root;
		node* makeEmpty(node* t);
		node* RecInsert(char x, node* t);
		node* findMax(node* t);
		node* remove(char x, node* t);
		void inorder(node* t);
		node* find(node* t, char x);
		node* findMin(node* t);
	public:
		BST();
		~BST();
		node* findMin();
		void Insert(char x);
		void remove(char x);
		void display();
		void search(char x);
		bool isEmpty() { if (root) return false; else return true;}
		node* findMinimum();
		node* getroot()const { return root; }
	};
}