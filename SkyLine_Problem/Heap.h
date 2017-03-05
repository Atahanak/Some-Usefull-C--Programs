#include <iostream>
#include <vector>

using namespace std;

struct nodeX
{
	int buildingLabel;
	string position;
	int xCoord;
	int h;

	nodeX () : buildingLabel(0), xCoord(-1), position(""), h(0) {}
};

struct nodeH
{
	int bLabel;
	int buildingHeight;

	nodeH () : bLabel(0), buildingHeight(0) {}
};

class Heap
{
private:
	vector<nodeH>  heightArray;
	vector<nodeX>  xCoordArray;
	vector<int> locationArray;
	int currentMax;
	int currentSize;
public:

	Heap(int size)
	:
	currentMax(0),
	currentSize(0),
	heightArray(size+1),
	xCoordArray(2*size+1),
	locationArray(size+1)
	{}
	//~Heap();
	bool isEmpty();
	void drawSkyline();
	void percolateDown(int pos);
	void removeHeight(int label);
	void insertXCoord(int label, string pos, int x, int h);
	void insertHeight(int label, int height);

	void sortxCoordArray();
	void heapSort(vector<nodeX> &a);
	void percDown(vector<nodeX>& a, int i, int n);
	int leftChild(int i);
};