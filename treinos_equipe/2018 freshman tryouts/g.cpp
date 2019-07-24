#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum = sum + a;
    }
    for(int i = 0; i <= 10; i++){
        if((sum + i) == 5*(n+1)){
            cout << "Sim" << endl;
            return 0;
        }
    }
    cout << "Nao" << endl;
}

