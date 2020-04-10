#include<bits/stdc++.h>
#define MAX 11234567
using namespace std;

int v[MAX], b;
string a;
bool ocr[MAX];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a.length() <= 7 && (b = stoi(a)) >= 0){
            ocr[b] = true;
        }
    }

    for(int i = 0; i <= n; i++){
        if(!ocr[i]){
            cout << i << endl;
            break;
        }
    }

    return 0;
}