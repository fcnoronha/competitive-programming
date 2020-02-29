//codeforces.com/contest/1315/problem/C

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

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int b[n];
        fr(i, n) cin >> b[i];
        vi ans(n+n, 0);
        fr(i, n) ans[i+i] = b[i];

        vi used(n+n+3, 0);
        fr(i, n) used[b[i]] = 1;

        fr(i, n) {

            int aux = ans[i+i];
            int idx = INF;
            for (int j = aux+1; j <= n+n; j++) {
                if (!used[j]) {
                    idx = j;
                    break;
                }
            }
            if (idx == INF) {
                p(-1);
                goto fim;
            }
            used[idx] = 1;
            ans[i+i+1] = idx;
        }   

        pv(ans); 
        fim: continue;
    }
}
