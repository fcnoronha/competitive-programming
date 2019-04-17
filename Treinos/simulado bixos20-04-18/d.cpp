#include <bits/stdc++.h>
using namespace std;

long long int fac(int n){
    if(n == 0) return 1;
    return n*fac(n-1);    
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0){
        cout << "0" << endl;
        return 0;
    }
    cout << fac(n+m)/( fac(n) * fac(m) ) << endl;
}
