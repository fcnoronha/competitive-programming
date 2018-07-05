#include <bits/stdc++.h>
using namespace std;

int pink[4001], purple[4001], n, r, pu, pi, mx;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string cor;
        cin >> r >> cor;
        mx = max(mx, r);
        if(cor == "pink"){
            pi++;
            pink[r]++;
        }
        else{
            pu++;
            purple[r]++;
        }
    }
    for(int i = 0; i < mx; i++){
        pi = pi - pink[i];
        // cout << "pi " << pi << endl;
        pu = pu - purple[i];
        // cout << "pu " << pu << endl;
        if(pi > pu){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}
