#include <iostream>

using namespace std;

struct BinaryNode
{
	string dictionaryWord;
	int code;
	BinaryNode * rightChild;
	BinaryNode * leftChild;

	BinaryNode() : rightChild(NULL), leftChild(NULL) {}
};

class binaryTree
{
public:
	int wordCode;

	binaryTree();
	~binaryTree();
	int searchWord(string word);
	void addWord(BinaryNode * node, string word, int code);

private:
	BinaryNode * head;
};