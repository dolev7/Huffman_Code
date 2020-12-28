#include<iostream>
#include "BST.h"
using namespace std;
namespace Hofman
{
       node* BST::makeEmptyRec(node* t) 
        {
            if (t == nullptr)
                return nullptr;
            {
                makeEmptyRec(t->left);
                makeEmptyRec(t->right);
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
            return findMinRec(root);
        }
        node* BST::findMinRec(node* t)
        {
            if (t == nullptr)
                return nullptr;
            else if (t->left == nullptr)
            {       
                return t;
            }
            else
                return findMinRec(t->left);
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
                temp = findMinRec(t->right);
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
                size--;
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

        node* BST::findRec(node* t, char x) 
        {
            if (t == nullptr)
                return nullptr;
            else if (x < t->_letter)
                return findRec(t->left, x);
            else if (x > t->_letter)
                return findRec(t->right, x);
            else
                return t;
        }
        void BST::find(char c)
        {
            root = findRec(root, c);
        }
        BST::BST() 
        {
            size = 0;
            root = nullptr;
        }

        BST::~BST()
        {
            root = makeEmptyRec(root);
        }
        void BST::makeEmpty()
        {
            makeEmptyRec(root);
        }

        void BST::Insert(char c)
        {
            node* found=findRec(root, c);
            if (found)
                (found->_frequency)++;
            else
            {
                root = RecInsert(c, root);
                size++;
            }
        }

        void BST::remove(char c)
        {
            root = remove(c, root);
        }
}