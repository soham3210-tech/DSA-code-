#include <iostream>
#include <vector>

using namespace std;

int hashFunction(int key, int size)
{
    return key % size;
}

int main()
{
    int size = 10;
    vector<int> hashTable(size, -1);

    int keys[] = {23, 45, 12};

    for (int i = 0; i < 3; i++)
    {
        int index = hashFunction(keys[i], size);
        hashTable[index] = keys[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << i << " -> " << hashTable[i] << endl;
    }
}