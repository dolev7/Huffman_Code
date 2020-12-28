#include<iostream>
#include "minHeap.h"
using namespace std;
namespace Hofman
{
	minHeap::minHeap(HoffmanNode** unsortedarr,int size)
	{
		allocated = false;
		maxSize = this->size = size;
		data = unsortedarr;
		this->size = size;
		floydBuild();
	}
	minHeap::~minHeap()
	{
		makeEmpty();
	}
	void minHeap::makeEmpty()
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
	bool minHeap::isEmpty()
	{
		if (size == 0)
			return true;
		else return false;
	}
	void  minHeap::floydBuild()
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			fixHeap(i);
	}
	void minHeap::Insert(HoffmanNode* toinsert)
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