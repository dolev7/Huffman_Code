/*Operating Instructions:
 1.Start the program.
 2.Enter the file name of the file(with the text that you want to make huffman code from) and press enter.
 3a.If the file doesn't exist or file name is incorrect - you will recive an error message.
 3b.Otherwise , the Huffman code will be displayed on the screen: the code for each letter, and the total file size. 
*/
#include "mainHead.h"
int main()
{
	char fileName[MAX_SIZE];
	cin >> fileName;// 1.get the file name from the user(keyboard).
	BST* tree = MakeTreeFromFile(fileName);//2.Make a binary search tree from the letters in the file.
	int size = tree->getSize();
	HoffmanNode* hofman = MakeHoffmanTree(tree);//3.Make Huffman Tree from the binary search tree using Huffman's algorithm
	printCode(hofman,size);//4+5. Print Huffman Code and the coded file size using the Huffman tree we have made. 
	delete tree; // delete the search tree.
	return 0;
}
