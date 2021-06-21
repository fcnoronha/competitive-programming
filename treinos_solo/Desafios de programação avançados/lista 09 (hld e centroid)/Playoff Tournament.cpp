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

int f[312345], n;
string s;

void update(int i) {

    char c = s[i-1];
    i = n-i+1;

    if (c == '?') {

        if (i*2 > n) {
            f[i] = 2;
            return;
        }

        // dbg(i);
        // dbg(f[i*2]);
        // dbg(f[i*2 + 1]);

        f[i] = f[i*2]+f[i*2 + 1];
        return;
    }

    if (c == '1') {

        if (i*2 > n) {
            f[i] = 1;
            return;
        }

        f[i] = f[i*2];
        return;
    }

    if (c == '0') {

        if (i*2 > n) {
            f[i] = 1;
            return;
        }

        f[i] = f[i*2 + 1];
        return;
    }
} 

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int k; cin >> k;

    cin >> s;
    n = s.size();

    frr(i, n) update(i);

    int q; cin >> q;

    while (q--) {

        int p; cin >> p;
        char c; cin >> c;

        s[p-1] = c;

        while (p <= n) {
            update(p);
            p = (n-p+1)/2;
            p = n-p+1;
        }

        // frr(i, n) cout << i << " " << f[i] << endl;
        p(f[1]);

    }
}
