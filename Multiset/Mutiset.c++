#include<iostream>
#include<set>
using namespace std;

int main(){

    // multiset allows duplicate values
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(5);
    // s.erase(3);
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<*s.lower_bound(4)<<endl;
    cout<<*s.upper_bound(5)<<endl;
    cout<<*s.upper_bound(10)<<endl;
    return 0;
}