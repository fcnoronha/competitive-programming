// http://codeforces.com/gym/101810/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
    int t; 
    cin >> t; 
    while (t--){
        ll x, n, h;
        cin >> x >> n; 
     
        vector<lll> v(n+3, 0);     
     
        if (n != 1) h = x/(n+(n-2));

        else{
            cout << x << endl;
            continue;
        }
        
        h = floor(h);

        int resto = x - h*(n+(n-2));
        
        if (h > 0)
            for (int i = 1; i <= n-2; i++)
                v[i] += h;        
        
        for (int i = 0; i < n; i++){
            v[i] += h;
            if (resto > 0){
                v[i]++;
                resto--;
            }  
        }
        
        for (int i = n-2; (i > 0) && (resto > 0); i--){
            v[i]++;
            resto--; 
        }
        
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }
}