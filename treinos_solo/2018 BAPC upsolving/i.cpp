#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)

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

#define maxn 100109

vector<pll> adj[maxn];
ll n, m, s, total;
ll p[maxn], dist[10][maxn], mask[maxn];
pll shelter[10];
bool seen[maxn];

struct fe {
    ll u, v;
    ll cap, flow = 0ll;
};

fe edges[maxn*40];
vl adjj[maxn];
ll lvl[maxn], ptr[maxn];
queue<ll> q;
ll cnt;

void init(ll n) {
    fr(i, n) adjj[i].clear();
}

void uninit() {
    cnt = 0;
}

void add_edge(ll u, ll v, ll cap) {
    edges[cnt] = {u, v, cap};
    adjj[u].pb(cnt++);
    edges[cnt] = {v, u, 0ll};
    adjj[v].pb(cnt++);
}

bool bfs(ll t) {
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll id: adjj[u]) {
            if (edges[id].cap - edges[id].flow < 1) continue;
            if (lvl[edges[id].v] != -1) continue;
            lvl[edges[id].v] = lvl[u]+1;
            q.push(edges[id].v);
        }
    }
    return lvl[t] != -1;
}

ll dfs(ll u, ll pushed, ll t) {
    if (!pushed) return 0ll;
    if (u == t) return pushed;
    for (ll &cid = ptr[u]; cid < adjj[u].size(); cid++) {
        ll id = adjj[u][cid];
        ll v = edges[id].v;
        ll lft = edges[id].cap - edges[id].flow;
        if (lvl[u] + 1 != lvl[v] || lft < 1)
            continue;
        ll tr = dfs(v, min(pushed, lft), t);
        if (!tr) continue;
        edges[id].flow += tr;
        edges[id^1].flow -= tr;
        return tr;
    }
    return 0;
}

ll dinic(ll s, ll t) {
    ll f = 0;
    while (1) {
        ms(lvl, -1ll);
        lvl[s] = 0;
        q.push(s);
        if (!bfs(t)) break;
        ms(ptr, 0ll);
        while (ll pushed = dfs(s, LINF, t))
            f += pushed;
    }
    return f;
}

bool solve(ll val) {
    
    ll so = n+12, si = n+13;
    init(n+20);
    ms(mask, 0);
    ms(seen, 0);

    fr(i, s) {
        ll cap = shelter[i].s;
        add_edge(so, n+i, cap);
        fr(j, n) 
            if (dist[i][j] <= val)
                mask[j] |= (1<<i);
    }

    vector<pll> aux;
    fr(i, n) {
        if (seen[i]) continue;
        seen[i] = 1;
        ll amt = p[i];
        for (ll j = i+1; j < n; j++) {
            if (mask[i] != mask[j]) continue;
            amt += p[j];
            seen[j] = 1;
        }
        aux.pb({i, amt});
    }

    fr(i, s) {
        for (auto x: aux) {
            ll u = x.f;
            if (mask[u]&(1<<i)) 
                add_edge(n+i, u, LINF);
        }   
    }

    for (auto x: aux) 
        add_edge(x.f, si, x.s);
    
    ll f = dinic(so, si);
    uninit();
    return (total == f);
}

int main(){

    scanf("%lld %lld %lld", &n, &m, &s);
    fr(i, n) scanf("%lld", &p[i]), total += p[i];
    
    ll u, v, w;
    fr(i, m) {
        scanf("%lld %lld %lld", &u, &v, &w);
        u--; v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    fr(i, s) {
        scanf("%lld %lld", &u, &w);
        u--;
        shelter[i] = {u, w};
    }

    ll hi = 0;
    fr(i, s) {
        ll *dv = dist[i];
        ms(seen, 0);

        set<pll> st;
        st.insert({0ll, shelter[i].f});
        while (!st.empty()) {
            pll aux = *st.begin();
            st.erase(aux);
            ll d = aux.f;
            u = aux.s;
            
            if (seen[u]) continue;
            seen[u] = 1;

            hi = max(hi, d);
            dv[u] = d;
           
            for (auto e: adj[u]) {
                v = e.f;
                w = e.s;
                if (seen[v]) continue;
                st.insert({d+w, v});
            }
        }
    }

    ll lo = 0, ans = LINF;
    while (lo <= hi) {

        ll mid = (hi+lo)/2;
        if (solve(mid)) {
            ans = min(ans, mid);
            hi = --mid;
        }
        else
            lo = ++mid;
    }

    printf("%lld\n", ans);
}
