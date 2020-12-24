#include<iostream>
#include "BST.h"
using namespace std;
namespace Hofman
{
       node* BST::makeEmpty(node* t) 
        {
            if (t == NULL)
                return NULL;
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            return NULL;
        }

        node* BST::insert(int x, node* t,char c)
        {
            if (t == NULL)
            {
                t = new node;
                t->data = c;
                t->key = x;
                t->left = t->right = NULL;
            }
            else if (x <= t->key)
                t->left = insert(x, t->left,c);
            else if (x > t->key)
                t->right = insert(x, t->right,c);
            return t;
        }

        node* BST::findMin(node* t)
        {
            if (t == NULL)
                return NULL;
            else if (t->left == NULL)
                return t;
            else
                return findMin(t->left);
        }

        node* BST::findMax(node* t)
        {
            if (t == NULL)
                return NULL;
            else if (t->right == NULL)
                return t;
            else
                return findMax(t->right);
        }

        node* BST::remove(int x, node* t)
        {
            node* temp;
            if (t == NULL)
                return NULL;
            else if (x < t->key)
                t->left = remove(x, t->left);
            else if (x > t->key)
                t->right = remove(x, t->right);
            else if (t->left && t->right)
            {
                temp = findMin(t->right);
                t->key = temp->key;
                t->right = remove(t->key, t->right);
            }
            else
            {
                temp = t;
                if (t->left == NULL)
                    t = t->right;
                else if (t->right == NULL)
                    t = t->left;
                delete temp;
            }

            return t;
        }

        void BST::inorder(node* t)
        {
            if (t == NULL)
                return;
            inorder(t->left);
            cout << t->key << " " << "'"<< t->data<<"'" <<endl;
            inorder(t->right);
        }

        node* BST::find(node* t, int x) 
        {
            if (t == NULL)
                return NULL;
            else if (x < t->key)
                return find(t->left, x);
            else if (x > t->key)
                return find(t->right, x);
            else
                return t;
        }
        BST::BST() 
        {
            root = NULL;
        }

        BST::~BST()
        {
            root = makeEmpty(root);
        }

        void BST::insert(int x,char c)
        {
            root = insert(x, root,c);
        }

        void BST::remove(int x)
        {
            root = remove(x, root);
        }

        void BST::display()
        {
            inorder(root);
            cout << endl;
        }

        void BST::search(int x) 
        {
            root = find(root, x);
        }
}