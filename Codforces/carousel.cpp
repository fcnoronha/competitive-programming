//codeforces.com/contest/1328/problem/D

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

    int q;
    cin >> q;
    while (q--) {

        int n;
        cin >> n;

        int t[n];
        fr(i, n) cin >> t[i];

        vi ans(n, 0);
        int col = 1;
        fr(i, n) {
            if (ans[i]) continue;
            ans[i] = col;
            int j = i+1;
            while (j < n && t[j] == t[i]) ans[j++] = ans[i];
            
            if (col == 1) col = 2;
            else if (col == 2) col = 1;
        }

        if (t[0] != t[n-1] && ans[0] == ans[n-1]) {
            if (ans[n-2]+ans[0] == 2) ans[n-1] = 2;
            else if ((ans[n-2]+ans[0] == 4)) ans[n-1] = 1;
            else {

                bool deu = 0;
                for (int i = n-2; i > 0; i--) {
                    if (ans[i] != ans[i-1]) continue;
                    
                    for (; i < n; i++) ans[i] = 3 - ans[i];
                    deu = 1;
                    break;
                }

                if (!deu) {
                    ans[n-1] = 3;
                }
            }
        }

        int k = *max_element(all(ans));
        p(k);
        pv(ans);
    }

}
