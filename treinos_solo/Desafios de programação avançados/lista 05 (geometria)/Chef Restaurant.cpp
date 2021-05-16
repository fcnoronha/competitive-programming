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

    int t; cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        pii op[n];
        fr(i, n) cin >> op[i].f >> op[i].s;
        sort(op, op+n);

        pii pv[m];
        fr(i, m) cin >> pv[i].f, pv[i].s = i;
        sort(pv, pv+m); // tem que acabar

        int ans[m];
        int j = 0;
        fr(i, m) {

            ini:;

            int curp = pv[i].f, idx = pv[i].s;
            if (j == n) {
                ans[idx] = (-1);
                continue;
            }

            int curl = op[j].f;
            int curr = op[j].s;

            if (curp <= curl) {
                ans[idx] = (curl - curp);
                continue;
            }

            if (curp < curr) {
                ans[idx] = (0);
                continue;
            }

            j++;
            goto ini;
        }

        fr(i, m) p(ans[i]);
    }
}
