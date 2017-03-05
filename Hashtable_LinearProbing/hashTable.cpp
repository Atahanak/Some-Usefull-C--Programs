#include <iostream>
#include "hashTable.h"

using namespace std;

HashTable::HashTable()
{
	currSize = 0;
	hashTable = new probe [hashSize];
	probesCond = 0;
}

double HashTable::loadFactor()
{
	return (double)currSize/(double)hashSize;
}

int HashTable::hashFunction(int integer, int i)
{
	return ((integer+i) % hashSize);
}

int HashTable::probesConducted()
{
	int p = probesCond;
	probesCond = 0;
	return p;
}

bool HashTable::isFull()
{
	if(currSize < hashSize)
	{
		return false;
	}
	return true;
}

int HashTable::hashInstert(int integer, HashTable & hs)
{
	bool flag = true;
	for(int i = 0; flag && !hs.isFull(); i++)
	{
		probesCond++;
		if(hashTable[hs.hashFunction(integer,i)].integer == -1)
		{
			hashTable[hs.hashFunction(integer,i)].integer = integer;
			currSize++;
			flag = false;
			return 1;
		}
	}
	return 0;
}

int HashTable::hashDelete(int integer, HashTable & hs)
{
	bool flag = true;
	for(int i = 0; flag && !hs.isFull(); i++)
	{
		probesCond++;
		if(hashTable[hs.hashFunction(integer,i)].integer == -1 && hashTable[hs.hashFunction(integer, i)].ereased == false)
		{
			flag = false;
			return 0;
		}
		else if(hashTable[hs.hashFunction(integer,i)].integer == integer)
		{
			hashTable[hs.hashFunction(integer,i)].integer = -1;
			hashTable[hs.hashFunction(integer, i)].ereased = true;
			currSize--;
			flag = false;
			return 1;
		}
	}
	return 0;	
}

int HashTable::hashFind(int integer, HashTable & hs)
{
	bool flag = true;
	for(int i = 0; flag && !hs.isFull(); i++)
	{
		probesCond++;
		if(hashTable[hs.hashFunction(integer,i)].integer == -1 && hashTable[hs.hashFunction(integer, i)].ereased == false)
		{
			flag = false;
			return 0;
		}
		else if(hashTable[hs.hashFunction(integer,i)].integer == integer)
		{
			flag = false;
			return 1;
		}
		
	}
	return 0;
}
	
