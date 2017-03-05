#include <iostream>

using namespace std;
struct probe
{
	int integer;
	bool ereased;
	probe () : integer(-1), ereased(false) {}
};

class HashTable
{
public:
	static const int hashSize = 10067; /*104729*/ /*10067*/
	HashTable();
	bool isFull();
	int hashFunction(int number, int i);
	double loadFactor();
	int probesConducted();
	int hashFind(int number, HashTable & hs);
	int hashDelete(int number, HashTable & hs);
	int hashInstert(int number, HashTable & hs);

private:
	int probesCond;
	int currSize;
	probe * hashTable;
};
