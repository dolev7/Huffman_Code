#pragma once
using namespace std;
#include "HoffmanTree.h"
#include "BST.h"
#include <vector>
namespace Hofman
{
	class minHeap
	{
	private:
		
		vector< HoffmanNode> Array;
		int size;
		const int Parent(int node);
		const int Left(int node);
		const int Right(int node);
		void fixHeap(int node);
		void floydBuild();
	public:
		minHeap(BST* searchtree);
		~minHeap() {};
		HoffmanNode* deleteMin() { return nullptr; }
		HoffmanNode* min() { return nullptr; }
		void Insert(HoffmanNode toinsert) {};
	};
}
