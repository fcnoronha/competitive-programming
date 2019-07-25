#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 112345

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vii v;

int vis[MAXN], n, q;

map<pii, int> id;

struct edge{
	int x, w;
};

vector<edge> edges[MAXN];

void dfs(int i, int mx){
	vis[i] = 1;
	int mn = INT_MAX, maximilian = 0, idx = -1;

	for(auto e: edges[i]){
		if(vis[e.x]) continue;
		maximilian = max(maximilian, e.w);
	}

	if(maximilian >= mx){
		for(auto e: edges[i]){
			if(vis[e.x] || e.w < mx) continue;
			mn = min(mn, e.w);
			dfs(e.x, max(mx, e.w));
		}
		
		if(mn >= mx + 1) v.pb({mx + 1, mn});

		id[{mx + 1, mn}] = i;	
	}

	else{
		for(auto e: edges[i]){
			if(vis[e.x] || e.w != maximilian) continue;
			mn = min(mn, e.w);
			dfs(e.x, max(mx, e.w));
		}
		
		if(mn >= mx + 1) v.pb({mx + 1, mn});

		id[{mx + 1, mn}] = i;	
	}

}



int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &q);
		frr(i, n) edges[i].clear();
		frr(i, n-1){
			vis[i] = 0;
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edges[u].pb({v, w});
			edges[v].pb({u, w});

		}

		vis[n] = 0;

		dfs(1, 0);
		sort(all(v));
		ll ans = 0;
		int vaca = v.size();
		fr(i, q){
			int x; scanf("%d", &x);
			int pos = lower_bound(all(v), mp(x, 0))-v.begin();
			if(pos == vaca) pos--;
			if(v[pos].first > x) pos--;
				
			ll retards = id[v[pos]];

			ans += retards;
		}

		printf("%lld\n", ans);
		v.clear();
		id.clear();
	}
}












