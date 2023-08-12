#include<iostream>
using namespace std;

int fo(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return fo(arr,n,i+1,key);
}


int lo(int arr[],int n,int i,int key){
   if(i==n){
    return-1;
   }
   int restarray=lo(arr,n,i+1,key);
   if (restarray!=-1)
   {
    return restarray;
   }
   if (arr[i]== key)
   {
    return i;
   }
   return -1;
   
}

int main(){
    int n,key;
    cin>>n>>key;
   int arr[n];
   for (size_t i = 0; i < n; i++)
   {
    cin>>arr[i];
   }
    cout<<fo(arr,n,0,key);
    cout<<" ";
    cout<<lo(arr,n,0,key);
   
    return 0;
}