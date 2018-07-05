#include <bits/stdc++.h>
using namespace std;

int flag[100000];
int pessoas[100000], pessoas2[100000];
 
int main(){
   int n, m, c = -1;
   cin >> n >> m;
   int a, b;
   for(int i = 0; i < m; i++){
        cin >> a >> b;
        
        if(flag[a] == 0 && flag[b] == 0){
            c++;
            pessoas[c] = a;
            pessoas2[c] = b;
            flag[a] = 1;
            flag[b] = 1;
        }
   }
   cout << c+1 << endl;
   for(int i = 0; i < c+1; i++){
        cout << pessoas[i] << " " << pessoas2[i] << endl;
   }   
}
