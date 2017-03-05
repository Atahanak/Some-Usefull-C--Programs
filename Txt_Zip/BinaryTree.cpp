#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

//Constructor
binaryTree::binaryTree()
{
	head = NULL;
}

//Destructor
binaryTree::~binaryTree()
{

}

int binaryTree::searchWord(string currentWord)
{
	if(currentWord.length() != 1)
	{
		if(head != NULL)
		{
			BinaryNode * temp = new BinaryNode;
			BinaryNode * previous = new BinaryNode;
			temp = head;
			int flag = 0;

			while(temp != NULL)
			{
				if(temp->dictionaryWord == currentWord)
				{
					return temp->code;
				}
				else if(temp->dictionaryWord > currentWord)
				{
					previous = temp;
					temp = temp->leftChild;
					flag = 1;
				}
				else if(temp->dictionaryWord < currentWord)
				{
					previous = temp;
					temp = temp->rightChild;
					flag = 2;
				}
			}
			wordCode++;
			BinaryNode * insertedNode = new BinaryNode;
			insertedNode->dictionaryWord = currentWord;
			insertedNode->code = wordCode;
			if(flag == 1)
			{
				previous->leftChild = insertedNode;
			}
			if(flag == 2)
			{
				previous->rightChild = insertedNode;
			}
			return -1;
		}
		else
		{
			wordCode = 256;
			head = new BinaryNode;
			head->code = wordCode;
			head->dictionaryWord = currentWord;
			return -1;
		}
	}
	return currentWord.at(0);
}

void binaryTree::addWord(BinaryNode * node, string currentWord, int currentCode)
{
	BinaryNode * insertedNode = new BinaryNode;
	insertedNode = node;
	insertedNode->dictionaryWord = currentWord;
	insertedNode->code = currentCode;
}