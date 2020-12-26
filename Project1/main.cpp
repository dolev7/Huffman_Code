
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BST.h"
#include "HoffmanTree.h"
#include "minHeap.h"
#include <vector>
#include <fstream>
static const int  MAX_SIZE = 128;
static const int  ASCII_SIZE = 128;
using namespace std;
using namespace Hofman;
BST* MakeTreeFromFile(const char* fname);
HoffmanNode* MakeHoffmanTree(BST* SearchTree);
void printCode(HoffmanNode* root);
void printAndDel(HoffmanNode* current);
int main()
{
	char fileName[MAX_SIZE];
	cin >> fileName;
	BST* tree = MakeTreeFromFile(fileName);
	tree->display();
	HoffmanNode* hofman = MakeHoffmanTree(tree);
	//HoffmanNode* hofman=new HoffmanNode('0',3);
	//HoffmanNode* left = new HoffmanNode('b', 2);
	//HoffmanNode* right = new HoffmanNode('c', 1);
	//hofman->setLeft(left);
	//hofman->setRight(right);
	printCode(hofman);
	return 0;
}
void printCode(HoffmanNode* root)
{
	while (root)
	{
		if (root->isLeaf())
		{
			delete root;
			return;
		}
		printAndDel(root);
		cout << endl;
	}
}
void printAndDel(HoffmanNode* current)
{
	if (current->isLeaf())
	{
		cout << "'" << current->getLetter() << "' - ";
		current->remove();
		return;
	}
	if (current->getLeft())
	{
		printAndDel(current->getLeft());
		cout << "0";
		return;
	}//else has right
	printAndDel(current->getRight());
	cout << "1";
}
HoffmanNode* MakeHoffmanTree(BST* SearchTree)
{
	minHeap Q(SearchTree);
	HoffmanNode current;
	while (true)
	{
		current= HoffmanNode();
		current.setLeft(Q.deleteMin());
		current.setRight(Q.deleteMin());
		current.setFreq(current.getLeftFreq() + current.getRightFreq());
		Q.Insert(current);
	}
	return Q.deleteMin();
}
BST* MakeTreeFromFile(const char* fname)
{
	
	char c;
	BST* res = new BST;
	ifstream inFile;
	inFile.open(fname);
	inFile >> noskipws >> c;
	while (!inFile.eof())
	{
		res->Insert(c);
		inFile >> noskipws >> c;
	}
	inFile.close();
	return res;
}