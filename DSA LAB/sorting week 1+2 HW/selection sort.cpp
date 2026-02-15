#include <iostream>
using namespace std;
int main()
{
    int arr[] = {8, 2, 4, 9, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<n-1; i++)
    {
        int minindex = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex = j;

            }
        }
        int temp = arr[i];
        arr[minindex] = temp;

    }
cout<< "Sorted: ";
for(int i = 0; i<n; i++)
cout<<arr[i] <<" ";
cout<< endl;
return 0;

}