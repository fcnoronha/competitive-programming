#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll x1, ll y1, ll x2, ll y2){
    return (y2*x1 - x2*y1);
}

int main() {
    int n, p;
    pair<int, int> v[60];
    ll area = 0, areat = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;    
        area = 0;            
        for(int j = 0; j < p; j++){
            cin >> v[j].first >> v[j].second;            
        }
        for(int j = 0; j < p; j++){
            area += f(v[j].first, v[j].second, v[(j+1) %p].first, v[(j+1) %p].second);
        }        
        if(area < 0) area = -area;
        areat += area;
    }
    areat /= 2;
    cout << areat << endl;

}