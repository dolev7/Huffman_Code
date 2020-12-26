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

        node* BST::RecInsert(char x, node* t)
        {
            if (t == nullptr)
            {
                t = new node;
                t->_letter = x;
                t->_frequency = 1;
                t->left = t->right = nullptr;
            }
            else if (x <= t->_letter)
                t->left = RecInsert(x, t->left);
            else if (x > t->_letter)
                t->right = RecInsert(x, t->right);
            return t;
        }
        node* BST::findMin()
        {
            return findMin(root);
        }
        /*node* BST::findMinimum()
        {
            return findMin(root);
        }*/
        node* BST::findMin(node* t)
        {
            if (t == nullptr)
                return nullptr;
            else if (t->left == nullptr)
            {       
                return t;
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

        node* BST::remove(char x, node* t)
        {
            node* temp;
            if (t == nullptr)
                return nullptr;
            else if (x<t->_letter || x==t->_letter && t->left)
                t->left = remove(x, t->left);
            else if (x > t->_letter)
                t->right = remove(x, t->right);
            else if (t->left && t->right)
            {
                temp = findMin(t->right);
                t->_letter = temp->_letter;
                t->right = remove(t->_letter, t->right);
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
            cout << t->_frequency << " " << "'"<< t->_letter <<"'" <<endl;
            inorder(t->right);
        }

        node* BST::find(node* t, char x) 
        {
            if (t == nullptr)
                return nullptr;
            else if (x < t->_letter)
                return find(t->left, x);
            else if (x > t->_letter)
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

        void BST::Insert(char c)
        {
            node* found=find(root, c);
            if (found)
                (found->_frequency)++;
            else
            root = RecInsert(c,root);
        }

        void BST::remove(char c)
        {
            root = remove(c, root);
        }

        void BST::display()
        {
            inorder(root);
            cout << endl;
        }

        void BST::search(char c) 
        {
            root = find(root, c);
        }
}