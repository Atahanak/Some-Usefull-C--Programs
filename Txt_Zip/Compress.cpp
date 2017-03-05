#include <iostream>
#include <string>
#include <fstream>
#include "binaryTree.h"

using namespace std;

int main()
{
	binaryTree compressTree;
	ifstream inputFile;
	ofstream outputFile;

	string fileString, line, prefix, prefixTemp, character;
	int j = 0, i = 0;

	inputFile.open("compin.txt");
	while(getline(inputFile, line))
	{
		fileString = fileString + line;
	}

	inputFile.close();

	outputFile.open("compout.txt");

	while(j < fileString.length())
	{
		bool flag = true;
		bool iterate = false;
		for(i=0; flag; i++)
		{
			prefixTemp = fileString.substr(j,i+1);
			if(compressTree.searchWord(prefixTemp) == -1 || i+j == fileString.length())
			{
				iterate = true;
				flag = false;
				outputFile << compressTree.searchWord(prefix) <<" ";
			}
			prefix = prefixTemp;
			if(iterate)
			{
				j = j + i;
			}
		}
	}
	
	outputFile.close();

	cin.get();
	cin.ignore();
	return 0;
}