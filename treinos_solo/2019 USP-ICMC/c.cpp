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

int main(){
    fastio;

    int n;
    cin >> n;

    vi mp[2009];
    int last_idx[2009];

    vi aux_x, aux_y;
    pii ori[n];
    fr(i, n) {
        int x, y;
        cin >> x >> y;
        ori[i] = {x, y};
        aux_x.pb(x);
        aux_y.pb(y);
    }
    
    // coodinate compress;
    sort(all(aux_y));
    sort(all(aux_x));
    map<int, int> cx, cy;
    int nx = 1, ny = 1;
    for (auto aux: aux_x) 
        if (cx[aux] == 0) cx[aux] = nx++;
    for (auto aux: aux_y)
        if (cy[aux] == 0) cy[aux] = ny++;

    fr(i, n) mp[ cy[ori[i].s] ].pb( cx[ori[i].f] );
    ms(last_idx, -1);
    
    ll ans = 0ll;
    fr(i, ny) {

        vi &v = mp[i];
        sort(all(v));
        
        fr(i, (int)v.size()-1) {

            // border
            int l1 = last_idx[v[i]];
            int l2 = last_idx[v[i+1]];
            if (l1 != l2 || l1 == -1) continue;


            int idx = l1;
            auto x1 = lower_bound(all(mp[idx]), v[i]);
            if (*x1 != v[i]) continue;
            x1++;
            if (*x1 != v[i+1]) continue;

            // inside
            for (int x = v[i]+1; x < v[i+1]; x++)
                if (last_idx[x] > l1) 
                    goto fim;

            ans++;
            fim: continue;
        }   
            
        for (int x: v) last_idx[x] = i;
    } 

    p(ans);
}
