#include<iostream>
#include "minHeap.h"
using namespace std;
namespace Hofman
{
	minHeap::minHeap(BST* searchtree)
	{
		size = searchtree->getSize();
		data = new HoffmanNode * [size];
		node* currentMin;
		HoffmanNode* current;
		for (int i = 0; i < size; i++)//fill the heap array from the BST.
		{
			currentMin = searchtree->findMin();
			current = new HoffmanNode(currentMin->_letter, currentMin->_frequency);
			data[i] = current;
			searchtree->remove(currentMin->_letter);
		}
		floydBuild();
	}
	void  minHeap::floydBuild()
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			fixHeap(i);
	}
	void minHeap::Insert(HoffmanNode* toinsert)
	{
		int i = size;
		size++;
		while (i > 0 && data[Parent(i)]->getFreq() > toinsert->getFreq())
		{
			data[i] = data[Parent(i)];
			i = Parent(i);
		}
		data[i] = toinsert;
	}
	HoffmanNode* minHeap::deleteMin()
	{
		if (size < 1)
		{
			cout << "invalid input";
			exit(1);
		}
		HoffmanNode* min = data[0];
		size--;
		data[0] = data[size];
		fixHeap(0);
		return min;
	}
	const int  minHeap::Parent(int node)const
	{
		return (node - 1) / 2;
	}
	const int minHeap::Left(int node)const
	{
		return (2 * node) + 1;
	}
	const int minHeap::Right(int node)const
	{
		return (2 * node) + 2;
	}
	void minHeap::fixHeap(int node)
	{
		int min;
		int left = Left(node);
		int right = Right(node);
		if (left < size && (data[left]->getFreq() < data[node]->getFreq()))
				min = left;
		else min = node;
		if (right < size)
		{
			if (data[right]->getFreq() < data[min]->getFreq())
				min = right;
		}
		if (min != node)
		{
			Swap(data[node], data[min]);
			fixHeap(min);
		}
	}
	void minHeap::Swap(HoffmanNode*& a, HoffmanNode*& b)
	{
		HoffmanNode* temp = a;
		a = b;
		b = temp;
	}
}