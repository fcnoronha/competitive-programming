#include<bits/stdc++.h>
#define fmax asdasda
using namespace std;

int n, z, firstmax, secondmax;
string fmax;
map<string, int> m;
string a;


int main(){
    firstmax = secondmax = INT_MIN;
    cin >> n;
    z = n;
    while(n--){
        cin >> a;
        m[a]++;
        if(m[a] > firstmax){
            firstmax = m[a];
            fmax = a;
        }
    }
    if(firstmax > z-firstmax){
        cout << fmax << endl;
    }
    else{
        cout << "NONE" << endl;
    }
    return 0;
}