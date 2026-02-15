#include<iostream>
using namespace std;
int main()
{
    int arr[8] = {23, 42, 82, 91, 92, 98, 108, 113};
    int tofind, left = 0, right = 7, mid;
    int flag =0;

    cin>> tofind;
    while(left<=right)
    { 
        mid = (left+right)/2;
        if(arr[mid]==tofind)
        {
            flag = 1;
            cout<<"Value found at index:" <<mid;
            break;
        }
        else if (tofind<arr[mid])
        { 
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
       }
    if (flag == 0)
        cout << "Value not found";

    return 0;
}
