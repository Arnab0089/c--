#include<iostream>
using namespace std;

// reverse  a string using recursion
void reverse(string s){
    if (s.length()==0)
    {
        return;
    }
    string ros=s.substr(1);
    reverse(ros);
    cout<<s[0];
}

int main(){
  string s;
  cin>>s;
  reverse(s);
   
    return 0;
}