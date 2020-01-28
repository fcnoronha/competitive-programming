//codeforces.com/gym/101908/problem/F

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

ll memo[87000][(1<<10)];
vector< pair< pll, ll > > show[87000];

int main(){
    fastio

    int n;
    cin >> n;

    fr(i, n) {

        int m;
        cin >> m;

        ll ini, fim, o;
        while (m--) {
            cin >> ini >> fim >> o;
            show[ini].pb({{fim, i}, o});
        }
    }

    ms(memo, -1);
    frr(i, 86400) {

        memo[i][0] = 0;

        // Carrying on results
        frr(j, (1<<n)-1)
            memo[i][j] = max(memo[i][j], memo[i-1][j]);

        for (auto sh : show[i]) {

            ll end = sh.f.f;
            ll stg = sh.f.s;
            ll val = sh.s;

            fr(j, (1<<n)) {

                // Nobody arrived here :(
                if (memo[i][j] == -1) continue;

                ll mask = j | (1<<stg);
                memo[end][mask] = max(memo[end][mask], memo[i][j] + val);
            }
        }
    }

    p(memo[86400][(1<<n)-1]);
}
