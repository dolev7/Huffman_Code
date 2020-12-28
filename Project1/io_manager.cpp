#include "mainHead.h"
BST* MakeTreeFromFile(const char* fname)
{
	char c;
	BST* res = new BST;
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
HoffmanNode** makeArrFromTree(BST* SearchTree,int* psize)
{
	int size = SearchTree->getSize();
	*psize = size;
	HoffmanNode** unsortedArr = new HoffmanNode * [size];//will be deleted before heap is deleted.
	node* currentMin;
	HoffmanNode* current;
	for (int i = 0; i < size; i++)//fill the array from the BST.
	{
		currentMin = SearchTree->findMin();
		current = new HoffmanNode(currentMin->_letter, currentMin->_frequency);//will be deleted during the code making (running through hoffman tree).
		unsortedArr[i] = current;
		SearchTree->remove(currentMin->_letter);
	}
	return unsortedArr;
}
HoffmanNode* MakeHoffmanTree(BST* SearchTree)
{
	int size;
	HoffmanNode** unsortedArr = makeArrFromTree(SearchTree,&size);
	minHeap Q(unsortedArr, size);
	HoffmanNode* current;
	while (Q.getsize() > 1)
	{
		current=new HoffmanNode();//will be deleted during the code making (running through hoffman tree).
		current->setLeft(Q.deleteMin());
		current->setRight(Q.deleteMin());
		current->setFreq(current->getLeftFreq() + current->getRightFreq());
		Q.Insert(current);
	}
	HoffmanNode* res = Q.deleteMin();
	delete[] unsortedArr;// the array is stored in the heap.
	return res;
}
void printCode(HoffmanNode* root, int size)
{
	cout << "Character encoding :" << endl;
	int filesize = 0;
	int currentCodeSize;
	vector<char> LetterCode;
	for (int i = 0; i < size; i++)
	{
		LetterCode.clear();
		currentCodeSize = 0;
		calcCode(root, &currentCodeSize, LetterCode);
		cout << endl;
		filesize += currentCodeSize;
	}
	cout << "Encoded file weight: " << filesize << " bits" << endl;
}
void printLetterCode(HoffmanNode* current, int* codedLetterSize, vector <char> LetterCode)
{
	if (current->getLetter() != '\n')
		cout << "'" << current->getLetter() << "' - ";
	else
		cout << "'\\n' - ";
	(*codedLetterSize) *= current->getFreq();
	for (int i = 0; i < LetterCode.size(); i++)
		cout << LetterCode[i];
}
void calcCode(HoffmanNode* current, int* codedLetterSize, vector <char> LetterCode)
{
	if (current->isLeaf())
	{
		printLetterCode(current, codedLetterSize, LetterCode);
		current->remove();
		return;
	}
	if (current->getLeft())
	{
		LetterCode.push_back('0');
		(*codedLetterSize)++;
		calcCode(current->getLeft(), codedLetterSize, LetterCode);
		return;
	}//else has right
	(*codedLetterSize)++;
	LetterCode.push_back('1');
	calcCode(current->getRight(), codedLetterSize, LetterCode);
}
