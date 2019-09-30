//codeforces.com/contest/1230/problem/D 

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio

    int n;
    cin >> n;

    vector<pll> v(n); // {a, b}
    fr(i, n)
        cin >> v[i].f;
    fr(i, n)
        cin >> v[i].s;

    map<ll, int> freq;
    for (auto u : v)
        freq[u.f]++;

    map<ll, bool> used;
    ll mx = 0ll;
    int cnt = 0;
    set<ll> st;
    for (auto u : v)
        if (freq[u.f] > 1) {
            st.insert(u.f);
            mx += u.s;
            used[u.f] = 1;
            cnt++;
        }

    if (cnt < 2) {
        cout << "0" << endl;
        return 0;
    }

    for (auto u : v) {
        if (used[u.f]) continue;
        for (auto x : st) {
            if (((u.f) | x) == x) {
                mx += u.s;
                break;
            }
        }
    }

    cout << mx << endl;
}
