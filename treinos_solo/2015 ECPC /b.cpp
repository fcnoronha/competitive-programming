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

        int q, m;
        cin >> q >> m;

        vector<vi> ans(q, vi(4, -1));
        while (m--) {
            fr(i, q) {

                char qst, op;
                cin >> qst >> op;

                int qn = (qst-'A');
                if (op == 'T') ans[i][qn] = 1;
                else ans[i][qn] = 0;
            }
        }

        int k = 0;
        for (auto x: ans) {
            int cnt = 0, tem = 0;
            fr(i, 4) cnt += (x[i] == 0), tem += (x[i] == 1);
            if (tem == 1) {
                fr(i, 4) 
                    if (x[i] == 1)
                        cout << char('A'+i);
            }
            else if (cnt == 3) {
                fr(i, 4) 
                    if (x[i] == -1)
                        cout << char('A'+i);
            }
            else {
                cout << "?";
            }
            if (k++ < q-1) cout << " ";
        }
        if (t) cout << "\n";
    }
}
