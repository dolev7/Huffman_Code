#pragma once
using namespace std;
#include "HoffmanTree.h"
#include "BST.h"
namespace Hofman
{
	class minHeap
	{
	private:
		HoffmanNode** data;
		int size;
		int maxSize;
		bool allocated;
		const int Parent(int node)const;
		const int Left(int node)const;
		const int Right(int node)const;
		void fixHeap(int node);
		void floydBuild();
		void Swap(HoffmanNode*& a, HoffmanNode*& b);
	public:
		minHeap(HoffmanNode** unsortedarr, int size);
		~minHeap();
		HoffmanNode* deleteMin();
		HoffmanNode* min()const { return data[0]; }
		const int getsize()const { return size; }
		void Insert(HoffmanNode* toinsert);
		bool isEmpty();
		void makeEmpty();
	};
}
