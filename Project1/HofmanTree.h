#pragma once
namespace Hofman
{
	struct node
	{
		int data;
		node* left;
		node* right;
	};
	class BST
	{
	private:

		node* root;
		node* makeEmpty(node* t);
		node* insert(int x, node* t);
		node* findMin(node* t);
		node* findMax(node* t);
		node* remove(int x, node* t);
		void inorder(node* t);
		node* find(node* t, int x);
	public:
		BST();
		~BST();
		void insert(int x);
		void remove(int x);
		void display();
		void search(int x);

	};
}