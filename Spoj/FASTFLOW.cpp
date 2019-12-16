//www.spoj.com/problems/FASTFLOW/

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define MAXN 5009
#define MAXM 150000

int nd, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int to[MAXM], nxt[MAXM];
ll cap[MAXM];

void init() {
   ms(first, -1);
   ms(cap, 0LL);
   nd = 0;
}

void add(int u, int v, ll f) {
	to[nd] = v, cap[nd] = f;
	nxt[nd] = first[u];
	first[u] = nd++;
	
	to[nd] = u, cap[nd] = 0LL;
	nxt[nd] = first[v];
	first[v] = nd++;
}

ll dfs (int u, ll f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0LL) {
			ll df = dfs(v, min(f, cap[e]), t);
			if (df > 0LL) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0LL;
}

bool bfs(int s, int t) {
	ms(dist, -1);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e != -1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0LL) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

ll dinic(int s, int t) {
	ll result = 0LL, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, LINF, t)) result += f;
	}
	return result;
}

int main() {
    fastio;

	int n, m, u, v;
    ll c;
    cin >> n >> m;
	init();
	
	fr(i, m) {
		cin >> u >> v >> c;
		add(u, v, c);
        add(v, u, c);
	}

	ll mf = dinic(1, n);
	cout << mf << endl;;
}