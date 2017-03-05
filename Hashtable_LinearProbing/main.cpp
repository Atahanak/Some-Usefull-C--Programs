#include <iostream>
#include <fstream>
#include "hashTable.h"

using namespace std;

/*

*/
void transactions(HashTable hashTable, ofstream & output1,  ofstream & output2,  ofstream & output3,  ofstream & output4,  ofstream & output5,  ofstream & output6, int i, int d, int f)
{
	cout<<"started";
	int m, t;
	/*if(i == 6)
	{
		outputFile.open("output1.csv");
	}
	else if(i == 4)
	{
		outputFile.open("output2.csv");
	}
	else
	{
		outputFile.open("output3.csv");
	}*/
	for(int j = 0; j < 1000000 && !hashTable.isFull(); j++)
	{
		t = rand() % 8;
		m = rand() % 10000000;
		if(i > t &&  t >= 0)
		{
			if(hashTable.hashInstert(m, hashTable) == 1)
			{
				output1<<"i,";
				output1<<hashTable.loadFactor();
				output1<<",";
				output1<<hashTable.probesConducted();
				output1<<"\n";
			}
			else
			{
				output2<<"i,";
				output2<<hashTable.loadFactor();
				output2<<",";
				output2<<hashTable.probesConducted();
				output2<<"\n";
			}
		}
		else if(i + d > t && t >= i)
		{
			if(hashTable.hashDelete(m, hashTable) == 1)
			{
				output3<<"d,";
				output3<<hashTable.loadFactor();
				output3<<",";
				output3<<hashTable.probesConducted();
				output3<<"\n";
			}
			else
			{
				output4<<"d,";
				output4<<hashTable.loadFactor();
				output4<<",";
				output4<<hashTable.probesConducted();
				output4<<"\n";
			}
		}
		else
		{
			if(hashTable.hashFind(m, hashTable) == 1)
			{
				output5<<"f,";
				output5<<hashTable.loadFactor();
				output5<<",";
				output5<<hashTable.probesConducted();
				output5<<"\n";
			}
			else
			{
				output6<<"f,";
				output6<<hashTable.loadFactor();
				output6<<",";
				output6<<hashTable.probesConducted();
				output6<<"\n";
			}
		}
	}
	cout<<"complete";
}

int main()
{
	HashTable hashTable, hashTable1, hashTable2;
	int i, d, f;
	ofstream inputFile1, inputFile2, inputFile3, inputFile4, inputFile5, inputFile6;
	ofstream inputFile7, inputFile8, inputFile9, inputFile10, inputFile11, inputFile12;
	ofstream inputFile13, inputFile14, inputFile15, inputFile16, inputFile17, inputFile18;
	/*

	*/
	inputFile1.open("i1s.txt");
	inputFile2.open("i1.txt");
	inputFile3.open("d1s.txt");
	inputFile4.open("d1.txt");
	inputFile5.open("f1s.txt");
	inputFile6.open("f1.txt");
	i = 6, d = 1, f = 1;
	transactions(hashTable, inputFile1, inputFile2, inputFile3, inputFile4, inputFile5, inputFile6,i, d, f);
	inputFile1.close();
	inputFile2.close();
	inputFile3.close();
	inputFile4.close();
	inputFile5.close();
	inputFile6.close();

	inputFile7.open("i2s.txt");
	inputFile8.open("i2.txt");
	inputFile9.open("d2s.txt");
	inputFile10.open("d2.txt");
	inputFile11.open("f2s.txt");
	inputFile12.open("f2.txt");
	i = 4, d = 2, f = 2;
	transactions(hashTable1, inputFile7, inputFile8, inputFile9, inputFile10, inputFile11, inputFile12,i, d, f);
	inputFile7.close();
	inputFile8.close();
	inputFile9.close();
	inputFile10.close();
	inputFile11.close();
	inputFile12.close();

	inputFile13.open("i3s.txt");
	inputFile14.open("i3.txt");
	inputFile15.open("d3s.txt");
	inputFile16.open("d3.txt");
	inputFile17.open("f3s.txt");
	inputFile18.open("f3.txt");
	i = 2, d = 1, f = 5;
	transactions(hashTable2, inputFile13, inputFile14, inputFile15, inputFile16, inputFile17, inputFile18,i, d, f);
	inputFile13.close();
	inputFile14.close();
	inputFile15.close();
	inputFile16.close();
	inputFile17.close();
	inputFile18.close();

	return 0;
}