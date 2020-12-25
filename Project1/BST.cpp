#include<iostream>
#include "BST.h"
using namespace std;
namespace Hofman
{
       node* BST::makeEmpty(node* t) 
        {
            if (t == nullptr)
                return nullptr;
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            return nullptr;
        }

        node* BST::insert(int x, node* t,char c)
        {
            if (t == nullptr)
            {
                t = new node;
                t->data = c;
                t->key = x;
                t->left = t->right = nullptr;
            }
            else if (x <= t->key)
                t->left = insert(x, t->left,c);
            else if (x > t->key)
                t->right = insert(x, t->right,c);
            return t;
        }
        node* BST::findAndDelMin()
        {
            return findMin(root);
        }
        node* BST::findMin(node* t)
        {
            if (t == nullptr)
                return nullptr;
            else if (t->left == nullptr)
            {
                node* res = new node;
                res->left = nullptr;
                res->right = nullptr;
                res->data = t->data;
                res->key = t->key;
                remove(t->key);
                return res;
            }
            else
                return findMin(t->left);
        }

        node* BST::findMax(node* t)
        {
            if (t == nullptr)
                return nullptr;
            else if (t->right == nullptr)
                return t;
            else
                return findMax(t->right);
        }

        node* BST::remove(int x, node* t)
        {
            node* temp;
            if (t == nullptr)
                return nullptr;
            else if (x<t->key || x==t->key && t->left)
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
                if (t->left == nullptr)
                    t = t->right;
                else if (t->right == nullptr)
                    t = t->left;
                delete temp;
            }

            return t;
        }

        void BST::inorder(node* t)
        {
            if (t == nullptr)
                return;
            inorder(t->left);
            cout << t->key << " " << "'"<< t->data<<"'" <<endl;
            inorder(t->right);
        }

        node* BST::find(node* t, int x) 
        {
            if (t == nullptr)
                return nullptr;
            else if (x < t->key)
                return find(t->left, x);
            else if (x > t->key)
                return find(t->right, x);
            else
                return t;
        }
        BST::BST() 
        {
            root = nullptr;
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