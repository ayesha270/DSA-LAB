#include <iostream>
using namespace std;

int main()
{
    int num[10] = {2, 2, 12, 15, 32, 57, 65, 77, 98, 99}; 
    int tosearch, l = 0, r = 9, mid;
    int flag = 0;

    cin >> tosearch;

    while (l <= r)
    {
        mid = (l+r) / 2;

        if (num[mid] == tosearch)
        {
            flag = 1;
            cout << "Value found at index: " << mid;
            break;
        }
        else if (tosearch < num[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (flag == 0)
        cout << "Value not found";

    return 0;
}


