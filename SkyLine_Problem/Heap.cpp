#include <iostream>
#include <string>

#include "Heap.h"

using namespace std;

bool Heap::isEmpty()
{
	return (heightArray[1].bLabel == 0);
}

void Heap::insertXCoord(int label, string pos, int x, int h)
{
	if(pos == "l")
	{
		xCoordArray[label].buildingLabel = (label+1)/2;
	}
	else
	{
		xCoordArray[label].buildingLabel = label/2;
	}
	xCoordArray[label].position = pos;
	xCoordArray[label].xCoord = x;
	xCoordArray[label].h = h;
}

void Heap::sortxCoordArray()
{
	heapSort(xCoordArray);
}

void Heap::heapSort(vector<nodeX> &a)
{
	for(int i = a.size()/2; i>=0; i--)
		percDown(a,i,a.size());

	for(int j=a.size()-1; j>0; j--)
	{
		swap(a[0], a[j]);
		percDown(a,0,j);
	}
}

void Heap::percDown(vector<nodeX> &a, int i, int n)
{
	int child;
	nodeX tmp;

	for(tmp = a[i]; leftChild(i)<n; i = child)
	{
		child = leftChild(i);
		if(child != n-1 && a[child].xCoord < a[child+1].xCoord)
			child++;
		if(a[child].xCoord > tmp.xCoord)
			a[i] = a[child];
		else
			break;
	}
	a[i] = tmp;
}

int  Heap::leftChild(int i)
{
	return 2*i+1;
}

void Heap::insertHeight(int label, int height)
{

	int hole = ++currentSize;

	for(;hole>1 && height > heightArray[hole/2].buildingHeight; hole /= 2)
	{
		heightArray[hole] = move(heightArray[hole/2]);
		locationArray[heightArray[hole].bLabel] = hole;
	}
	
	heightArray[hole].buildingHeight = height;
	heightArray[hole].bLabel = label;
	locationArray[heightArray[hole].bLabel] = hole;
}

void Heap::removeHeight(int label)
{
	if(!isEmpty())
	{
		heightArray[locationArray[label]] = heightArray[currentSize];
		heightArray[currentSize].bLabel = 0;
		heightArray[currentSize--].buildingHeight = 0;
		percolateDown(locationArray[label]);
	}
}

void Heap::percolateDown(int hole)
{
	int child;
	nodeH tmp = heightArray[hole];

	for(; hole*2<=currentSize; hole = child)
	{
		child = hole*2;
		if(child != currentSize && heightArray[child+1].buildingHeight>heightArray[child].buildingHeight)
			child++;
		if(heightArray[child].buildingHeight > tmp.buildingHeight) 
			heightArray[hole] = heightArray[child];
		else
			break;
	}
	heightArray[hole] = tmp;
}

void Heap::drawSkyline()
{
	if(xCoordArray[1].xCoord != 0)//Initialization
	{
		cout<< "0 " << currentMax <<endl;
	}

	for(int i = 1; i<xCoordArray.size(); i++)//In every iteration checks whether the currentMax has changed 
	{
		if(xCoordArray[i].position == "l")//when left add height to the max heap
		{
			insertHeight(xCoordArray[i].buildingLabel, xCoordArray[i].h);
			//Changed code here
			while(i < xCoordArray.size()-1 && xCoordArray[i].xCoord == xCoordArray[i+1].xCoord)
			{
				if(xCoordArray[i+1].position == "r")
				{
					removeHeight(xCoordArray[i+1].buildingLabel);
				}
				else
				{
					insertHeight(xCoordArray[i+1].buildingLabel, xCoordArray[i+1].h);
				}
				i++;
			}
			//to here
			
			if(heightArray[1].buildingHeight != currentMax)
			{
				currentMax = heightArray[1].buildingHeight;
				cout<< xCoordArray[i].xCoord <<" "<< currentMax <<endl;
			}
		}
		else if(xCoordArray[i].position == "r")//when right remove height from the max heap
		{
			removeHeight(xCoordArray[i].buildingLabel);
			//changed code here
			while(i < xCoordArray.size()-1 && xCoordArray[i].xCoord == xCoordArray[i+1].xCoord)
			{
				if(xCoordArray[i+1].position == "r")
				{
					removeHeight(xCoordArray[i+1].buildingLabel);
				}
				else
				{
					insertHeight(xCoordArray[i+1].buildingLabel, xCoordArray[i+1].h);
				}
				i++;
			}
			//to here
			
			if(heightArray[1].buildingHeight != currentMax)
			{
				currentMax = heightArray[1].buildingHeight;
				cout<< xCoordArray[i].xCoord <<" "<< currentMax <<endl;
			}
		}
	}
}