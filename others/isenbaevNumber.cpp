//acm.timus.ru/problem.aspx?space=1&num=1837

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
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

vi adj[905];
bool vis[905];
int cnt, baev_id, mn;

int bfs(int v) {

    queue< pii > st;
    st.push({v, 0});

    while (!st.empty()) {

        pii aux = st.front();
        st.pop();

        v = aux.f;
        int cnt = aux.s;

        if (vis[v]) continue;
        vis[v] = 1;

        if (v == baev_id)
            return cnt;


        for (auto u : adj[v])
            st.push({u, cnt+1});

    }

    return -1;
}

int main(){
	fastio

    int n;
    cin >> n;

    map<string, int> mp;
    vector<string> ans;
    string aux;

    vector<string> prev;
    fr(i, n) {

        fr(j, 3) {

            cin >> aux;

            if (mp.find(aux) == mp.end()) {
                mp[aux] = cnt++;
                ans.pb(aux);
            }

            int this_id = mp[aux];

            for (auto s : prev) {

                int that_id = mp[s];

                adj[that_id].pb(this_id);
                adj[this_id].pb(that_id);
            }

            prev.pb(aux);
        }

        prev.clear();
    }

    if (mp.find("Isenbaev") != mp.end()) baev_id = mp["Isenbaev"];
    else baev_id = -1;

    sort(all(ans));

    for (auto x : ans) {

        ms(vis, 0);

        mn = bfs(mp[x]);
        if (mn >= 0) cout << x << " " << mn << "\n";
        else cout << x << " undefined\n";
    }

    return 0;
}
