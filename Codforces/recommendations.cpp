//codeforces.com/contest/1315/problem/D

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

int main() {
    fastio;

    int n;
    cin >> n;

    map<ll, ll> amt;
    map<ll, bool> used;
    set<ll> avlb;
    multiset<pll> seti;
    pll aux[n];
    fr(i, n) cin >> aux[i].f;
    fr(i, n) cin >> aux[i].s;

    ll ans = 0ll;
    fr(i, n) {
        ll np = aux[i].f;
        ll t = aux[i].s;
        amt[np]++;
        seti.insert({-t, np});
        // used[np] = 1; 
    }
    //fr(i, n) if (!used[aux[i].f+1]) avlb.insert(aux[i].f+1);
    
    while (!seti.empty()) {
        pll oi = *seti.begin();
        seti.erase(seti.find(oi));
        ll np = oi.s;
        ll t = -oi.f;

        if (!used[np]) {
            used[np] = 1;
            if (avlb.find(np) != avlb.end()) avlb.erase(np);
            if (!used[np+1]) avlb.insert(np+1);
            continue;
        }

        ll nw = *avlb.upper_bound(np);
        avlb.erase(nw);
        used[nw] = 1;
        if (!used[nw+1]) avlb.insert(nw+1);
        ans += (nw-np)*t; 
    }

    p(ans);
}
