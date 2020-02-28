//codeforces.com/contest/1313/problem/C

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

    ll n;
    cin >> n;

    ll h[n];
    fr(i, n) cin >> h[i];

    pll ans = {0, 0};
    ll aux, l, r;
    fr(i, n) {

        l = r = aux = h[i];
        for (int j = i+1; j < n; j++) {
            r = min(r, h[j]);
            aux += r;
        }
        for (int j = i-1; j >= 0; j--) {
            l = min(l, h[j]);
            aux += l;
        }
        ans = max(ans, {aux, i});
    }

    l = r = h[ans.s];
    for (int j = ans.s+1; j < n; j++) {
        r = min(r, h[j]);
        h[j] = r;
    }
    for (int j = ans.s-1; j >= 0; j--) {
        l = min(l, h[j]);
        h[j] = l;
    }
    fr(i, n) cout << h[i] << " \n"[i == n-1];
}
