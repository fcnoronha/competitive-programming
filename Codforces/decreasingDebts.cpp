//codeforces.com/contest/1266/problem/D

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

#define maxn 100009

int n, m;

ll amt[maxn];

int main(){
    fastio;

    cin >> n >> m;

    fr(i, m) {
        ll u, v, d;
        cin >> u >> v >> d;
        amt[u] += d;
        amt[v] -= d;
    }

    vector< pair<pll, ll> > ans;
    int v = 1;
    
    frr(u, n) {

        if (amt[u] <= 0) continue;
        
        while (amt[u] > 0) {

            while (v <= n && amt[v] >= 0) v++;
            ll z = min(amt[u], -amt[v]);
            ans.pb({{u,v}, z});
            amt[u] -= z;
            amt[v] += z;
        }
    }

    p(ans.size());
    for (auto a: ans) 
        cout << a.f.f << " " << a.f.s << " " << a.s << endl;
}
