#include <iostream>
#include <fstream>
#include <sstream>

#include "Heap.h"

using namespace std;

int main()
{
	ifstream fs;
	string line, height, xR, xL;
	string begining = "l", ending = "r";
	fs.open("input.txt");
	
	(getline(fs, line));
	istringstream sr(line);
	Heap heap(stoi(line));

	for(int i = 1; getline(fs, line); i++) //Constructs the cordinate array
	{
		istringstream ss(line);
		ss >> xL;
		ss >> height;
		ss >> xR;

		heap.insertXCoord(2*i-1, begining, stoi(xL), stoi(height));
		heap.insertXCoord(2*i, ending, stoi(xR), stoi(height));
	}

	heap.sortxCoordArray(); //sorts the cordinate array according to the buildings x cordinate in ascending order.
	heap.drawSkyline();

	return 0;
}