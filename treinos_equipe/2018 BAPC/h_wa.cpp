#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ll dp[200200][2];
map<ll, pll> adj[200200]; 
map<pll,ll> onstack;


ll solve(ll i, ll rato){

    if(onstack[{i,rato}] != 0) return LINF;
    if(dp[i][rato] != -1) return dp[i][rato];

    onstack[{i,rato}] = 1;
    if(rato == 0){
        ll z = LINF;
        dp[i][rato] = -LINF;
        for(auto x : adj[i]){
            dp[i][rato] = max(dp[i][rato], x.s.s + solve(x.f,!rato));
        }
    }
    else{
        dp[i][rato] = LINF;
        for(auto x : adj[i]){
            dp[i][rato] = min(dp[i][rato], x.s.f + solve(x.f, !rato));
        }
    }

    onstack[{i,rato}] = 0;
    return dp[i][rato];
}



int main(){
    fastio;
    ll n,m,s,t;
    cin >> n>> m >> s >> t;
    ms(dp,-1);
    dp[t][0] = dp[t][1] = 0;
    fr(i,m){
        ll a, b, c;
        cin >> a >> b >> c;
        
        if (adj[a].find(b) == adj[a].end()) {
            adj[a][b] = {c,c};
            continue;
        }
        
        adj[a][b].f = min(adj[a][b].f, c);
        adj[a][b].s = max(adj[a][b].s, c);
    }

    ll z = solve(s,0);
    if(z>=LINF) cout << "infinity" << endl;
    else cout << z << endl;
}
