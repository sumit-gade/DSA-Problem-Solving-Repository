#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string,int> umap;

    umap["prince"]=44;
    umap["gfg"]=56;
    umap["hello"]=90;

    umap.insert(make_pair(" sumit",10000));

    //for(auto x:umap)
    //cout<<x.first<<" "<<x.second<<endl;

    for(auto it=umap.begin(); it!=umap.end();it++)
    cout<<it->first<<" "<<it->second<<endl;

    string key="prince";

    /*if(umap.find(key)!=umap.end())
    cout<<" key found"<<endl;
    else
    cout<<" key not fund"<<endl;*/

      if(umap.find(key)!=umap.end()){
        auto temp =umap.find(key);
      cout<<" key is "<<temp ->first<<endl;
      cout<<"value is "<<temp->second<<endl; 
      }

      int arr[]={1,2,3,4,5,6,7,8,8,3,4,5,1,1,};

      

      unordered_map<int,int> ump;

      for(int i=0;i<14;i++)
      {

        int key = arr[i];
        ump[key]++;


      }

      for(auto it=ump.begin(); it!=ump.end();it++)
    cout<<it->first<<" "<<it->second<<endl;

      
    


    
     return 0;
}