//codeforces.com/contest/1335/problem/E2

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

#define maxn 212345
int pre_sm[maxn][201];
vi app[201];

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        int v[n];
        fr(i, n) cin >> v[i];

        fr(i, n+4) fr(j, 201) pre_sm[i][j] = 0;
        fr(i, 201) app[i].clear();

        fr(i, n) {
            pre_sm[i+1][v[i]]++;
            app[v[i]].pb(i+1);
            fr(j, 201) pre_sm[i+1][j] += pre_sm[i][j];
        }

        int ans = 0;
        fr(j, 201) ans = max(ans, pre_sm[n][j]);
        
        frr(p, 200) {

            if (app[p].empty()) continue;
            fr(i, (app[p].size())/2) {
                int l = app[p][i];
                int r = app[p][app[p].size()-i-1];
                int aux = 0;
                frr(j, 200) aux = max(aux, pre_sm[r-1][j]-pre_sm[l][j]);
                ans = max(ans, aux+((i+1)*2));
            }
        }

        p(ans);
    }
}
