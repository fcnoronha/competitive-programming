//codeforces.com/contest/1539/problem/D

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n; cin >> n;

    ll sma = 0;
    map<ll, ll> mp;
    fr(i, n) {
        ll a, b; cin >> a >> b;
        mp[b] += a;
        sma += a;
    }

    ll bt = 0; // comprados
    ll ans = 0; // gasto

    vl v; // bs em ordem crescente
    for (auto x: mp) v.pb(x.f);
    
    int l = 0, r = v.size()-1;
    while (bt < sma) {
        
        ll hb = v[l]-bt; // has to buy

        while (hb > 0 && bt < sma) {
            ll x = min(hb, mp[v[r]]);
            mp[v[r]] -= x;
            hb -= x;
            ans += x+x;
            bt += x;

            if (bt == sma) break;
            if (mp[v[r]] == 0) r--;
        }

        if (bt == sma) break;

        bt += mp[v[l]];
        ans += mp[v[l]];
        mp[v[l]] = 0;
        l++;
    }

    p(ans);
}
