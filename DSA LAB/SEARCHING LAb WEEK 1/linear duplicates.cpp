#include<iostream>
using namespace std;

int main()
{ 
    int num[10]={77, 98, 32, 65, 2, 99, 12, 15, 2, 57};
    int tosearch, flag=0, i;

    cin >> tosearch;

    for(i=0; i<10; i++)
    {
        if(tosearch == num[i])
        {
            flag = 1;
            cout << "Value found at index: " << i<<endl;
        }
    }

    if(flag == 0)
        cout << "Value not found";

    return 0;
}
