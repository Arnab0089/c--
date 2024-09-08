#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(5); // it will not insert 5 again as set does not allow duplicate values
      for(auto i:s){
            cout<<i<<" ";
      }
      cout<<endl;
      for(auto i=s.begin();i!=s.end();i++){
            cout<<*i<<" ";
      }
      // reverse order prrint of set
      cout<<endl;
      for(auto i=s.rbegin();i!=s.rend();i++){
            cout<<*i<<" ";
      }

      set<int ,greater<int>> r;
      r.insert(1);
      r.insert(2);
      r.insert(3);
      r.insert(4);
      r.insert(5);
      r.insert(5); // it will not insert 5 again as set does not allow duplicate values
      cout<<endl;
      for(auto i:r){
            cout<<i<<" ";
      }
   return 0;
}