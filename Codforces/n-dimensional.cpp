// http://codeforces.com/gym/101810/problem/E

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

const ll mod = 1e9+7;

ll fstExp(ll n, ll exp){
    if (exp == 0) return 1;
    
    ll aux;
    aux = fstExp(n, exp/2);
    aux = (aux*aux)%mod;
    if (exp%2) aux = (aux*n)%mod;
    return aux;    
}

ll invMod(ll x){
    return fstExp(x, mod-2);
}

int main(){
    int t;
    scanf("%d", &t);
    
    int inv[100009];
    for(int i = 0; i < 100002; i++)
        inv[i] = invMod(i);
    
    while(t--){
        
        int n, i;
        scanf("%d", &n);
        
        int a[n+3];
        
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);        
        
        ll mul = a[0];
        for (i=1; i<n; i++){
            mul *= a[i];
            mul %= mod;
        }
        
        ll ans = 0;
        for (i = 0; i < n; i++){
            ll aux = 0;
            aux = mul*inv[a[i]];
            aux = aux%mod;
            
            ans = (ans + aux*(a[i]-1))%mod;
        }        
        printf("%Ld\n", ans);            
    }
}