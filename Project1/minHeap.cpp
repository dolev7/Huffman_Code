#include<iostream>
#include "minHeap.h"
using namespace std;
namespace Hofman
{
	minHeap::minHeap(BST* searchtree)
	{
		size = 0;
		node* currentMin;
		HoffmanNode current;
		while (!searchtree->isEmpty())
		{
			currentMin=searchtree->findMin();
			current=HoffmanNode(currentMin->_letter, currentMin->_frequency);
			Array.push_back(current);
			searchtree->remove(currentMin->_letter);
			size++;
		}
	}
}