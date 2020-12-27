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
		floydBuild();
	}
	void  minHeap::floydBuild()
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			fixHeap(i);
	}
	const int  minHeap::Parent(int node)
	{
		return (node - 1) / 2;
	}
	const int minHeap::Left(int node)
	{
		return (2 * node + 1);
	}
	const int minHeap::Right(int node)
	{
		return (2 * node + 2);
	}
	void minHeap::fixHeap(int node)
	{
		int max;
		int left = Left(node);
		int right = Right(node);
		// to implent
		return;
	}
}