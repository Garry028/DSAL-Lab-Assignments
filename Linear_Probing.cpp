#include <iostream>
#define SIZE 10
using namespace std;

int HashFunction(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = HashFunction(key);
    int i = 0;
    while (H[index + 1] % SIZE != 0)
    {
        i++;
    }
    return (index + i) % SIZE;
}

void insert(int H[], int key)
{
    int index = HashFunction(key);
    if (H[index] != 0)
    {
        index = probe(H, key);
        H[index] = key;
    }
}

int search(int H[], int key)
{
    int index = HashFunction(key);

    int i = 0;
    while (H[(index + 1) % SIZE] != key)
    {
        i++;
    }
    return (index + i) % SIZE;
}

int main()
{
    int HT[10] = {0};
    insert(HT, 10); // this will insert at index 0
    insert(HT, 22); // this will insert at index 2
    insert(HT, 99); // this will insert at index 9
    cout << "kEY found at " << search(HT, 22);
    return 0;
}