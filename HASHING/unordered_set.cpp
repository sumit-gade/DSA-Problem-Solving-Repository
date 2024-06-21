#include<iostream>
#include<unordered_set>
using namespace std;

int main(){

    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.insert(20);

    for(auto it=s.begin(); it!=s.end(); it++)
    
    cout<<(*it)<<endl;

    cout<<"number of elements : " << s.size()<<endl;

    // s.clear();

   // cout<<"number of elements : " << s.size()<<endl;

   int key=20;

   if(s.find(key)==s.end()){

    cout<<"key not found"<<endl;

   }
   else{
    cout<<"key found"<<endl;
   }

   if(s.count(5))
   cout<<"key foound"<<endl;
   else
   cout<<"not found"<<endl;


    
    
     return 0;
}