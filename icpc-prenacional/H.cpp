#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;++i)
#define vi vector<int>

int main(){

  string s;cin>>s;
  int it=0;
  int maxi=-1;
  int posi=-1;
  fore(i,0,size(s)) {
    if(s.at(i)=='+') it++;
    else it--;
    if(it>maxi){
      maxi=it;posi=i;
    }
  }
  cout<<posi+1<<endl;
  return 0;
}