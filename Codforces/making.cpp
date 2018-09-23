// http://codeforces.com/gym/101810/problem/H

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
    int t = 0;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        
        int v[2*n+1];
        for (int i = 0; i < n*2; i++){
            cin >> v[i];
        }
            
        int mx = 0;
        for (int i = 0; i < n; i++){
            mx = max(mx, v[i]+v[(2*n)-i-1]);
        }
        
        cout << mx << endl;
            
    }
}
