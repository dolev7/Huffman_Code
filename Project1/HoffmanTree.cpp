#include<iostream>
#include "HoffmanTree.h"
using namespace std;
namespace Hofman
{
    /*node* HoffmanTree::makeEmpty(node* t)
    {
        if (t == nullptr)
            return nullptr;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return nullptr;
    }*/

    /*void HoffmanTree::insert(node* root1,node* root2)
    {
        int rootNum = root1->key + root2->key;
        if (t == nullptr)
        {
            t = new node;
            t->data = c;
            t->key = x;
            t->left = t->right = nullptr;
        }
        else if (x <= t->key)
            t->left = insert(x, t->left, c);
        else if (x > t->key)
            t->right = insert(x, t->right, c);
        return t;*/
    //}

    void HoffmanTree::inorder(node* t)
    {
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->key << " " << "'" << t->data << "'" << endl;
        inorder(t->right);
    }
    HoffmanTree::HoffmanTree(node* root1, node* root2)
    {
        root = new NumberNode;
        root->left = root1;
        root->right = root2;
        root->sum = root1->key+root2->key;
        if (root1->key <= root2->key)
        {
            root->left = root1;
            root->right = root2;
        }
        else
        {
            root->left = root2;
            root->right = root1;
        }
    }

    /*HoffmanTree::~HoffmanTree()
    {
        root = makeEmpty(root);
    }*/

    /*void HoffmanTree::insert(int x, char c)
    {
        root = insert(x, root, c);
    }*/
  /*  void HoffmanTree::display()
    {
        inorder(root);
        cout << endl;
    }*/
    /*node* HoffmanTree::insert(int x, node* t, char c)
    {
        if (t == nullptr)
        {
            t = new node;
            t->data = c;
            t->key = x;
            t->left = t->right = nullptr;
        }
        else if (x <= t->key)
            t->left = insert(x, t->left, c);
        else if (x > t->key)
            t->right = insert(x, t->right, c);
        return t;
    }*/
}