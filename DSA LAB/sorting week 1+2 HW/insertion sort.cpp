#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    
    int arr[n];
    cout<< "Enter"<<n<<"elements:";
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }
    // insertion sort
    for(int i = 1; i<n; i++){
        int hold = arr[i];
        int gap = i-1;
        while(gap>=0 && arr[gap]>hold){
            arr[gap+1] = arr[gap];
            gap--;       
        }
        arr[gap+1] = hold;
    }    

cout<<"sorted:";
for(int i =0; i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}