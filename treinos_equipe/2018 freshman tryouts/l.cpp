#include <bits/stdc++.h>
using namespace std;

int main(){
    string p;
    getline(cin, p);
    for(int i = 0; i < p.size(); i++){
        if(p[i] == 'P' and p[i+1] == 'E') i++;
        else cout << p[i];
    }
    cout << endl;
}
