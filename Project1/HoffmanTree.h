#pragma once
using namespace std;
namespace Hofman
{
		struct Hnode
		{
			int key;
			char data;
			Hnode* left;
			Hnode* right;
		};
		class Hoffman
		{
		private:

			Hnode* root;
			Hnode* makeEmpty(Hnode* t);
			Hnode* insert(int x, Hnode* t, char c);
			void inorder(Hnode* t);
			Hnode* find(Hnode* t, int x);
		public:
			Hoffman();
			~Hoffman();
			void insert(int x, char c);
			void remove(int x);
			void display();
			void search(int x);

		};
}
