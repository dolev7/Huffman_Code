#include "mainHead.h"
int main()
{
	char fileName[MAX_SIZE];
	cin >> fileName;
	BST* tree = MakeTreeFromFile(fileName);
	int size = tree->getSize();
	HoffmanNode* hofman = MakeHoffmanTree(tree);
	printCode(hofman,size);
	delete tree;
	return 0;
}
