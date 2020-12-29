#include "mainHead.h" // this module is the Input / Output manager- handles the main program features. 
BST* MakeTreeFromFile(const char* fileName)
{
	char c;
	BST* res = new BST;// we make an empty Binary Search Tree.
	ifstream inFile;
	inFile.open(fileName);
	if (!inFile.is_open())// Check if the file actually opened 
	{
		cout << "invalid input";
		exit(1);
	}
	inFile >> noskipws >> c; //read one character at a time including all ascii chars - (spaces,\n etc). 
	while (!inFile.eof())
	{
		res->Insert(c); // insert each letter into the tree- (Key=letter,data=frequency) - if the letter already exist on the tree:
		inFile >> noskipws >> c;//The insert function will increase frequency by 1 otherwise it will create a new letter with frequency=0    
	}
	inFile.close(); // close the file as we will longer need it .
	return res;//return the binary search tree we created and filled from the file .
}
HoffmanNode** makeArrFromTree(BST* SearchTree,int& psize)//this function creates an array from the search tree.
{
	int size = SearchTree->getSize();
	psize = size;
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
	HoffmanNode** unsortedArr = makeArrFromTree(SearchTree,size); // we use an array made from the tree
	PriorityQueue Q(unsortedArr, size); // we make a priority queue implented by using heap that is being created by using floyd's algorithm.
	HoffmanNode* current;
	while (Q.getsize() > 1)
	{
		current=new HoffmanNode();//will be deleted during the code making (running through hoffman tree).
		current->setLeft(Q.deleteMin());// left of the current node is the minimal node in the priority queue.
		current->setRight(Q.deleteMin()); // right is the 2nd minimal node in the prirotiy queue.
		current->setFreq(current->getLeftFreq() + current->getRightFreq()); // current is a "number only node" containing of Left and Right Frequency 
		Q.Insert(current);// insert current into the priority queue
	}
	HoffmanNode* res = Q.deleteMin();
	delete[] unsortedArr; // we delete the array as his elements 
	return res;
}
void printCode(HoffmanNode* root, int size)
{
	int filesize = 0;// the total file size.
	int currentCodeSize;//  the code size of current letter
	vector<char> LetterCode; // we use this array for printing the code in the right place - after the letter is printed.
	cout << "Character encoding :" << endl;
	if (root->isLeaf())//special case were the file has only 1 character. : we print 1 and the fie size will be the the amount of times this character is written
	{
		LetterCode.push_back('1'); 
		currentCodeSize = 1;
		printLetterCode(root, currentCodeSize, LetterCode);
		root->remove();
		filesize += currentCodeSize;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			LetterCode.clear();//we init the array to be empty.
			currentCodeSize = 0;// we init each letter code size to 0 .
			calcCode(root, currentCodeSize, LetterCode); // this function calcs and print the code for the current letter code and updates the current coded size 
			filesize += currentCodeSize; // we update the total file size to the total of all letter code sizes.
		}
	}
	cout << "Encoded file weight: " << filesize << " bits" << endl;// we print the sum of all the letter weight's - the file weight.
}
void printLetterCode(HoffmanNode* current, int& codedLetterSize, vector <char> LetterCode)
{
	if (current->getLetter() != '\n')
		cout << "'" << current->getLetter() << "' - ";
	else
		cout << "'\\n' - ";
	codedLetterSize *= current->getFreq();
	for (int i = 0; i < LetterCode.size(); i++)
		cout << LetterCode[i];
	cout << endl;
}
void calcCode(HoffmanNode* current, int& codedLetterSize, vector <char> LetterCode)
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
		codedLetterSize++;
		calcCode(current->getLeft(), codedLetterSize, LetterCode);
		return;
	}//else has right
	codedLetterSize++;
	LetterCode.push_back('1');
	calcCode(current->getRight(), codedLetterSize, LetterCode);
}
