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
		// get parent get left get right?
		void fixHeap();
	public:
		minHeap(BST* searchtree);
		~minHeap() {};
		HoffmanNode* deleteMin() { return nullptr; }
		HoffmanNode* min() { return nullptr; }
		void Insert(HoffmanNode toinsert) {};
	};
}
