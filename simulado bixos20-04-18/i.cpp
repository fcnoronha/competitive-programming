#include <bits/stdc++.h>
using namespace std;

long long int prob[26], flag[26];

int main(){
   int n,k;
   long long int t,sum=0;
   char aux;
   int id;
   string cond;
   
   cin >> n >> k;
   
   for(int i=0;i<k;i++){
      cin >> aux >> t >> cond;
      id=aux-'A';
      if(cond=="WA"){
        prob[id]-=20;
      }
      else if(flag[id] == 0){
        sum+=t+abs(prob[id]);
        flag[id] = 1;
      }
   }
   cout << sum << endl;

}


