
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BST.h"
#include "HoffmanTree.h"
#include "minHeap.h"
#include <vector>
#include <fstream>
#include <stdlib.h>
static const int  MAX_SIZE = 128;
using namespace std;
using namespace Hofman;
BST* MakeTreeFromFile(const char* fname);
HoffmanNode* MakeHoffmanTree(BST* SearchTree);
void printCode(HoffmanNode* root,int size);
void printAndDel(HoffmanNode* current, int* codedLetterSize, vector <char> LetterCode);
int main()
{
	char fileName[MAX_SIZE];
	cin >> fileName;
	BST* tree = MakeTreeFromFile(fileName);
	tree->display();
	int size = tree->getSize();
	HoffmanNode* hofman = MakeHoffmanTree(tree);
	printCode(hofman,size);

	return 0;
}
void printCode(HoffmanNode* root, int size)
{
	cout << "Character encoding :" << endl;
	int filesize = 0;
	int currentCodeSize;
	vector<char> LetterCode;
	for(int i=0;i<size;i++)
	{
		LetterCode.clear();
		currentCodeSize = 0;
		printAndDel(root,&currentCodeSize,LetterCode);
		cout << endl;
		filesize += currentCodeSize;
	}
	
	cout << "Encoded file weight: " << filesize << " bits"<< endl;
}
void printAndDel(HoffmanNode* current,int* codedLetterSize,vector <char> LetterCode)
{
	if (current->isLeaf())
	{
		if(current->getLetter() != '\n')
		cout << "'" << current->getLetter() << "' - ";
		else
			cout << "'\\n' - ";
		(*codedLetterSize)*=current->getFreq();
		for (int i = 0; i < LetterCode.size(); i++) cout << LetterCode[i];
		current->remove();
		return;
	}
	if (current->getLeft())
	{
		LetterCode.push_back('0');
		(*codedLetterSize)++;
		printAndDel(current->getLeft(),codedLetterSize,LetterCode);
		return;
	}//else has right
	(*codedLetterSize)++;
	LetterCode.push_back('1');
	printAndDel(current->getRight(),codedLetterSize,LetterCode);
}
HoffmanNode* MakeHoffmanTree(BST* SearchTree)
{
	minHeap Q(SearchTree);
	HoffmanNode* current;
	while (Q.getsize()>1)
	{
		current=new HoffmanNode();
		current->setLeft(Q.deleteMin());
		current->setRight(Q.deleteMin());
		current->setFreq(current->getLeftFreq() + current->getRightFreq());
		Q.Insert(current);
	}
	return Q.deleteMin();
}
BST* MakeTreeFromFile(const char* fname)
{
	char c;
	BST* res = new BST;//need to delete it 
	ifstream inFile;
	inFile.open(fname);
	if (!inFile.is_open())
	{
		cout << "invalid input";
		exit(1);
	}

	inFile >> noskipws >> c;
	while (!inFile.eof())
	{
		res->Insert(c);
		inFile >> noskipws >> c;
	}
	inFile.close();
	return res;
}