//codeforces.com/contest/1330/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

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

    ll n, m;
    cin >> n >> m;
    ll  l[m];
    fr(i, m) cin >> l[i];
    vl ans(n, -1);

    ll sm = 0ll;
    fr(i, m) sm += l[i];
    if (sm < n) {
        cout << -1 << endl;
        return 0;
    }

    vl p(m);
    fr(i, m) p[i] = i;     
    fr(i, m) {
        if (l[i]+p[i] > n) {
            cout << -1 << endl;
            return 0;
        } 
    }

    for (int i = m-1; i > 0; i--) {

        if (i == m-1) {
            p[i] = (n-l[i]);
            continue;
        }
        
        if (p[i]+l[i] >= p[i+1]) break;
        p[i] = p[i+1]-l[i];
    }

    for (auto &x: p) x++; 
    pv(p);
}
