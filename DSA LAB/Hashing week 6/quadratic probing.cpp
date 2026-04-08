#include <iostream>
using namespace std;

int main()
{
    int table[10];

    // initialize
    for(int i=0;i<10;i++)
        table[i] = -1;

    int keys[] = {23, 33, 43};

    for(int k=0;k<3;k++)
    {
        int key = keys[k];
        int index = key % 10;

        int i = 0;
        while(table[(index + i*i) % 10] != -1)
            i++;

        table[(index + i*i) % 10] = key;
    }

    // display
    for(int i=0;i<10;i++)
        cout << table[i] << " ";

    return 0;
}
