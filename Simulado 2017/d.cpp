#include <bits/stdc++.h>
using namespace std;

int prod[100000];

int main(){
    int n;
    long long total = 0;
    cin  >> n;
    cin >> prod[0];
    for(int i = 1; i < n; i++){
        cin >> prod[i];
        for(int j = 0; j < i; j++){
            total = total + prod[i]*prod[j]; 
        }
    }
    cout << total << endl;
}
