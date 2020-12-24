
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BST.h"
#include <fstream>
static const int  MAX_SIZE = 128;
using namespace std;
using namespace Hofman;
BST* MakeTreeFromFile(const char* fname);
int main()
{
	char fileName[MAX_SIZE];
	cin >> fileName;
	BST* tree = MakeTreeFromFile(fileName);
	tree->display();
	return 0;
}
BST* MakeTreeFromFile(const char* fname)
{
	int c;
	BST* res = new BST;
	ifstream inFile;
	inFile.open(fname);
	inFile >> c;
	res->insert(c);
	return res;
}