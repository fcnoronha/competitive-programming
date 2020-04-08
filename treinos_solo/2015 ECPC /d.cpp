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

#define maxn 112345

vector<pll> adj[maxn];

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        fr(i, n+2) adj[i].clear();
        fr(i, n-1) {
            ll p, c;
            cin >> p >> c;
            adj[p].pb({i+2, c});
        }

        int q;
        cin >> q;
        vector<pll> ans(q);
        fr(i, q) {

            ll tm;
            cin >> tm;
            ans[i] = {tm, i};
        }

        sort(all(ans));
        int cnt = 0, idx = 0;

        // pair == <time stamp, arrival node>
        set<pll> st;
        st.insert({0ll, 1});
        while (!st.empty()) {

            pll aux = *st.begin();
            st.erase(aux);

            ll arrival_time = aux.f;
            int cur_node = aux.s;

            // hey there, i am a leaf
            if (adj[cur_node].size() == 0) {
                while (idx < q && ans[idx].f < arrival_time) {
                    ans[idx].f = cnt;
                    idx++;
                }
                cnt++;
                continue;
            }

            ll mn_flow = LINF;
            for (auto x: adj[cur_node]) 
                if (x.s < mn_flow) 
                    mn_flow = x.s;

            for (auto x: adj[cur_node]) {
                if (x.s == mn_flow) 
                    st.insert({mn_flow + arrival_time, x.f});
                else 
                    st.insert({(x.s-mn_flow)*2 + mn_flow + arrival_time, x.f});
            }
        }


        while (idx < q) {
            ans[idx].f = cnt;
            idx++;
        }
        for (auto &x: ans) swap(x.f, x.s);
        sort(all(ans));
        for (auto x: ans) p(x.s);
    }
}
