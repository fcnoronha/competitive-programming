//codeforces.com/contest/1272/problem/B

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

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int u = 0, d = 0, l = 0, r = 0;

        for (auto c: s) {
            if (c == 'U') u++;
            if (c == 'D') d++;
            if (c == 'L') l++;
            if (c == 'R') r++;
        }

        u = min(u, d);
        r = min(r, l);

        if (!u) r = min(1, r);
        if (!r) u = min(1, u);

        p(2*u+2*r);

        fr(i, r) cout << 'R';
        fr(i, u) cout << 'U';
        fr(i, r) cout << 'L';
        fr(i, u) cout << 'D';

        cout << endl;
    }
}
