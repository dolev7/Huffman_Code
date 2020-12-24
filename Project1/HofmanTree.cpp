#include<iostream>
#include "HofmanTree.h"
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

    node* BST::insert(int x, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }
    void BST::inorder(node* t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
    BST::BST()
    {
        root = NULL;
    }

    BST::~BST()
    {
        root = makeEmpty(root);
    }

    void BST::insert(int x)
    {
        root = insert(x, root);
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