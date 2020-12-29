#include<iostream>
#include "HoffmanTree.h"
using namespace std;
namespace Hofman
{
	HoffmanNode::HoffmanNode(char letter, int frequency)
	{
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
		this->_frequency = frequency;
		this->_letter = letter;
	}
	bool HoffmanNode::isLeaf()const 
	{
		if (left == nullptr && right == nullptr)
			return true;
		return false;
	}
	void HoffmanNode::remove()
	{	
		HoffmanNode* parent = this->parent;
		if (parent)
		{
			if (parent->left == this)
				parent->left = nullptr;
			else if (parent->right == this)
			parent->right = nullptr;
		}
		delete this;
		if (parent)
		{
			if (parent->isLeaf())
				parent->remove();
		}
	}
}