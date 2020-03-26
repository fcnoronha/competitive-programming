//codeforces.com/contest/1327/problem/B

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

#define maxn 100009

bool seen[maxn], ma[maxn];
vi adj[maxn];

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        fr(i, n) seen[i] = ma[i] = 0;
        fr(i, n) {
            int k;
            cin >> k;
            adj[i].clear();

            int aux;
            fr(j, k) {
                cin >> aux;
                aux--;
                adj[i].pb(aux);
            }
        }

        fr(i, n) {
            for (auto g: adj[i]) {
                if (!seen[g]) {
                    seen[g] = 1;
                    ma[i] = 1;
                    break;
                }
            }
        }

        int cnt = 0;
        fr(i, n) cnt += seen[i];

        if (cnt == n) {
            p("OPTIMAL");
            continue;
        }

        p("IMPROVE");
        int idx = 0;
        while (seen[idx]) idx++;
        int pr = 0;
        while (ma[pr]) pr++;

        cout << pr+1 << " " << idx+1 << endl;
    }
}
