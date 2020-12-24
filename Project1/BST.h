#pragma once
namespace Hofman
{
	struct node 
	{
		int key;
		char data;
		node* left;
		node* right;
	};
	class BST
	{
	private:
		
		node* root;
		node* makeEmpty(node* t);
		node* insert(int x, node* t,char c);
		node* findMin(node* t);
		node* findMax(node* t);
		node* remove(int x, node* t);
		void inorder(node* t);
		node* find(node* t, int x);
	public:
		BST();
		~BST();
		void insert(int x,char c);
		void remove(int x);
		void display();
		void search(int x);
		
	};
}