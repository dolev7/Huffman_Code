
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BST.h"
#include "HoffmanTree.h"
#include <fstream>
static const int  MAX_SIZE = 128;
static const int  ASCII_SIZE = 128;
using namespace std;
using namespace Hofman;
BST* MakeTreeFromFile(const char* fname);
HoffmanTree* MakeHoffmanTree(BST* SearchTree);
int main()
{
	char fileName[MAX_SIZE];
	cin >> fileName;
	BST* tree = MakeTreeFromFile(fileName);
	tree->display();
	HoffmanTree* hofman = MakeHoffmanTree(tree);
	return 0;
}
HoffmanTree* MakeHoffmanTree(BST* SearchTree)
{
	node* min1; node* min2;
	while (!SearchTree->isEmpty())
	{
		min1 = SearchTree->findAndDelMin();
		min2 = SearchTree->findAndDelMin();
		HoffmanTree res(min1,min2);
		break;
	}
	return nullptr;
}
BST* MakeTreeFromFile(const char* fname)
{
	int LetterBuckets[ASCII_SIZE];
	for (int i = 0; i < ASCII_SIZE; i++)
		LetterBuckets[i] = 0;
	char c;
	BST* res = new BST;
	ifstream inFile;
	inFile.open(fname);
	inFile >> noskipws >> c;
	while (!inFile.eof())
	{
	LetterBuckets[c]++;
	inFile >> noskipws >> c;
	}
	inFile.close();
	for (int i = 0; i < ASCII_SIZE; i++)
	{
		if (LetterBuckets[i] > 0)
			res->insert(LetterBuckets[i], i);
	}
	return res;
}