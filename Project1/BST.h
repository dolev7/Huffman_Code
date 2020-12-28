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
		int size;
		node* root;
		node* makeEmptyRec(node* t);
		node* RecInsert(char x, node* t);
		node* remove(char x, node* t);
		void inorder(node* t);
		node* findRec(node* t, char x);
		node* findMinRec(node* t);
	public:
		BST();
		~BST();
		node* findMin();
		void Insert(char x);
		void remove(char x);
		void find(char x);
		bool isEmpty() { if (root) return false; else return true;}
		const int getSize()const { return size; }
		node* getroot()const { return root; }
		void makeEmpty();
	};
}