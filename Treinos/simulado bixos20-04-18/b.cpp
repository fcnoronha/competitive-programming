#include <bits/stdc++.h>
using namespace std;

string tags[1000], nomes[10];

int main(){
   string uni,time;
   int n,k;
   cin >> n >> k;
   int flag=0;
   int count=0;
   
   for(int i=0;i<n;i++){
      cin >> uni;
      getchar();
      cin >> time;
      getchar();
      tags[i]=uni;
      for(int j=0;j<i;j++){
        if(tags[j]==uni){
            flag=1; 
            break;
        }
      }
      
     if(flag==0){   
        nomes[count]=time;
         count++;
     }
     flag=0;
   }
   
   for(int i=0;i<k;i++){
        if(nomes[i]=="")    break; 
        cout << nomes[i] << endl;
        
   }
   
}
