
// C++ program to sort a string of characters
#include<bits/stdc++.h>
using namespace std;

// remove all duplicate string


string removeDupli(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=removeDupli(s.substr(1));
    if (ch==ans[0])
    {
        return ans;
    }
    return (ch+ans);
}


int main(){
  string s="aabbkka";
  
    cout<<removeDupli(s);
    return 0;
}