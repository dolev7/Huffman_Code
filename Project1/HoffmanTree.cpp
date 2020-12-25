#include<iostream>
#include "HoffmanTree.h"
using namespace std;
namespace Hofman
{
    Hnode* HoffmanTree::makeEmpty(Hnode* t)
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

    void HoffmanTree::insert(Hnode* root1,Hnode* node2)
    {
        if (t == NULL)
        {
            t = new Hnode;
            t->data = c;
            t->key = x;
            t->left = t->right = NULL;
        }
        else if (x <= t->key)
            t->left = insert(x, t->left, c);
        else if (x > t->key)
            t->right = insert(x, t->right, c);
        return t;
    }

    Hnode* HoffmanTree::findMin(Hnode* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    Hnode* HoffmanTree::findMax(Hnode* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    Hnode* HoffmanTree::remove(int x, Hnode* t)
    {
        Hnode* temp;
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

    void HoffmanTree::inorder(Hnode* t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->key << " " << "'" << t->data << "'" << endl;
        inorder(t->right);
    }

    Hnode* HoffmanTree::find(Hnode* t, int x)
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
    HoffmanTree::HoffmanTree()
    {
        root = NULL;
    }

    HoffmanTree::~HoffmanTree()
    {
        root = makeEmpty(root);
    }

    void HoffmanTree::insert(int x, char c)
    {
        root = insert(x, root, c);
    }

    void HoffmanTree::remove(int x)
    {
        root = remove(x, root);
    }

    void HoffmanTree::display()
    {
        inorder(root);
        cout << endl;
    }

    void HoffmanTree::search(int x)
    {
        root = find(root, x);
    }
}