#pragma once
using namespace std;
#include "BST.h"
namespace Hofman
{
	struct NumberNode
	{
		int sum;
		node* left;
		node* right;
	};
		class HoffmanTree
		{
		private:
			node* makeEmpty(node* t);
		public:
			NumberNode* root;
		//	void makeEmpty(node* t);
			void insert(node* root1, node* node2);
			void inorder(node* t);
			HoffmanTree(node* root1, node* root2);
	//		~HoffmanTree();
	//		void display();

		};
}
