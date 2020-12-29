#include<iostream>
#include "PriorityQueue.h"
using namespace std;
namespace Hofman
{
	PriorityQueue::PriorityQueue(HoffmanNode** unsortedarr,int size)
	{
		allocated = false;
		maxSize = this->size = size;
		data = unsortedarr;
		this->size = size;
		floydBuild();
	}
	PriorityQueue::~PriorityQueue()
	{
		makeEmpty();
	}
	void PriorityQueue::makeEmpty()
	{
		if (allocated)
		{
			for (int i = 0; i < size; i++)
				delete data[i];
			delete[]data;
		}
		data = nullptr;
		size = 0;
	}
	bool PriorityQueue::isEmpty()const
	{
		if (size == 0)
			return true;
		else return false;
	}
	void  PriorityQueue::floydBuild()
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			fixHeap(i);
	}
	void PriorityQueue::Insert(HoffmanNode* toinsert)
	{
		if (size == maxSize)
		{
			cout << "input error";
			exit(0);
		}
		int i = size;
		size++;
		while (i > 0 && data[Parent(i)]->getFreq() > toinsert->getFreq())
		{
			data[i] = data[Parent(i)];
			i = Parent(i);
		}
		data[i] = toinsert;
	}
	HoffmanNode* PriorityQueue::deleteMin()
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
	const int  PriorityQueue::Parent(int node)const
	{
		return (node - 1) / 2;
	}
	const int PriorityQueue::Left(int node)const
	{
		return (2 * node) + 1;
	}
	const int PriorityQueue::Right(int node)const
	{
		return (2 * node) + 2;
	}
	void PriorityQueue::fixHeap(int node)
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
	void PriorityQueue::Swap(HoffmanNode*& a, HoffmanNode*& b)
	{
		HoffmanNode* temp = a;
		a = b;
		b = temp;
	}
}