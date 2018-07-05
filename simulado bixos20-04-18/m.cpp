#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, s = 1, sum = 0;
    cin >> h;
    for(int i = 0; i < h; i++){
        sum = s*s + sum;
        s = s + 2;
    }
    cout << sum << endl; 
}
