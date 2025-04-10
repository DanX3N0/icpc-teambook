#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;i++)

int main() {

   int t;
   cin >> t;

   while(t--) {
      int c, e;
      cin >> c >> e;
      if(e <= 2 * c) {
         cout << "SI" << endl;
      } else {
         cout << "NO" << endl;
      }
   }


   return 0;
}