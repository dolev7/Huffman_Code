#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BST.h"
#include "HoffmanTree.h"
#include "minHeap.h"
#include <vector>
#include <fstream>
#include <stdlib.h>
static const int  MAX_SIZE = 128;
using namespace std;
using namespace Hofman;
BST* MakeTreeFromFile(const char* fname);
HoffmanNode* MakeHoffmanTree(BST* SearchTree);
void printCode(HoffmanNode* root, int size);
void calcCode(HoffmanNode* current, int& codedLetterSize, vector <char> LetterCode);
void printLetterCode(HoffmanNode* current, int& codedLetterSize, vector <char> LetterCode);
HoffmanNode** makeArrFromTree(BST* SearchTree, int& psize);