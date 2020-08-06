//codeforces.com/contest/1399/problem/D

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        string s;
        cin >> s;

        int j = 0;
        vector<vi> v;
        stack<int> on, zr;
        fr(i, n) {

            if (s[i] == '1') {
                if (on.empty()) {
                    vi aux;
                    aux.pb(i);
                    v.pb(aux);
                    zr.push(j++);
                }
                else {
                    int jj = on.top();
                    on.pop();
                    v[jj].pb(i);
                    zr.push(jj);
                }
            }
            else {
                if (zr.empty()) {
                    vi aux;
                    aux.pb(i);
                    v.pb(aux);
                    on.push(j++);
                }
                else {
                    int jj = zr.top();
                    zr.pop();
                    v[jj].pb(i);
                    on.push(jj);
                }
            }

        }

        int ans[n];
        fr(i, j) {
            for (auto x: v[i]) ans[x] = i+1;
        }

        p(j);
        fr(i, n) cout << ans[i] << " \n"[i==n-1];
    }
}
