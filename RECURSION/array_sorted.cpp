#include<iostream>
using namespace std;


// array sorted in cases of strictly increasing
bool sorted(int arr[],int n){
    if (n==1)
    {
        return true;
    }
    
    bool restarray=sorted(arr+1,n-1);
    if (arr[0]<arr[1]&&restarray){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<sorted(arr,n-1);
    
    return 0;
}