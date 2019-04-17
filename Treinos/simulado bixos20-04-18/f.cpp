#include <bits/stdc++.h>
using namespace std;

int primos[100000], num[100000], p = 3;

void fprimos(int N, int mx){
    if(primos[p] >= mx) return;
    bool primo = true;
    if(N > mx){
        return;
    }
    for(int i = 0; primos[i]*primos[i] <= N; i++){
        if(N%primos[i] == 0){
            primo = false;
            return;
        }
    }
    primos[p] = N;
    p++;
    fprimos(N+2, mx);
}


int main(){   
   int n;
   primos[0] = 3, primos[1] = 5, primos[2] = 7;
   cin >> n;
   for(int i = 0; i < n; i++){
        cin >> num[i];  
   }
   sort(num, num+n);
   fprimos(3, num[n-1]);
   cout << primos[4] << endl;
   for(int i = 0; i < n; i++){
        int flag = 1;
        for(int j = 0; primos[j]*primos[j] < num[i]; j++){
            if(num[i]%primos[j] == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout << num[i] << endl;
            return 0;
        } 
   }
   cout << "-1" << endl;
}
