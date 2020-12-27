#pragma once
using namespace std;
#include "BST.h"
namespace Hofman
{
		class HoffmanNode
		{
		private:
			char _letter;
			int _frequency;
			HoffmanNode* left; HoffmanNode* right;
			HoffmanNode* parent;
		public:
			HoffmanNode() { _letter = 0; _frequency = 0; left = nullptr; right = nullptr; parent = nullptr; };
			HoffmanNode(char letter, int frequency);
			~HoffmanNode() {};
			HoffmanNode* getLeft() const{ return left; }
			HoffmanNode* getRight() const{ return right; }
			int getLeftFreq() const { return left->_frequency; }
			int getRightFreq() const { return right->_frequency; }
			int getFreq ()const { return _frequency; }
			char getLetter()const { return _letter; }
			void setFreq(const int toset) { _frequency = toset; }
			void setLetter(const char toset) { _letter = toset; }
			void setLeft(HoffmanNode* Left) { left = Left; Left->parent = this; }
			void setRight(HoffmanNode* Right) { right = Right; Right->parent = this; };
			void remove();
			bool isLeaf();
		};
}
