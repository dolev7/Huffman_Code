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
		node* insert(int x, node* t,char c);
		node* findMax(node* t);
		node* remove(int x, node* t);
		void inorder(node* t);
		node* find(node* t, int x);
		node* findMin(node* t);
	public:
		BST();
		~BST();
		node* findAndDelMin();
		void insert(int x,char c);
		void remove(int x);
		void display();
		void search(int x);
		bool isEmpty() { if (root) return false; else return true;}
		node* findMinimum();
		node* getroot()const { return root; }
	};
}