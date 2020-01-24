	#include <bits/stdc++.h>
	using namespace std;

	#define pb push_back
	#define mp make_pair
	#define fst first
	#define snd second

	#define fr(i,n) 	for(int i=0;i<n;i++)
	#define frr(i,n)	for(int i=1;i<=n;i++)
	#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
	#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
	#define vp(v)        pv(v, v.size()) 


	#define ms(x,i)	memset(x,i,sizeof(x))
	#define dbg(x)	cout << #x << " = " << x << endl
	#define all(x)	x.begin(),x.end()
	#define otp(x) cout << x << endl;
	#define rvr(x) int x; scanf("%d", &x)
	#define gnl cout << endl
	#define olar cout << "olar" << endl
	#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

	typedef long long int ll;
	typedef pair<int,int> pii;
	typedef vector<int> vi;
	typedef vector<pii> vii;
	typedef vector<ll> vll;
	typedef pair<ll,ll> pll;

	const int INF = 0x3f3f3f3f;
	const ll llINF = 0x3f3f3f3f3f3f3f;
	const int MAXN = 1e4 + 1;
	const int MAXM = 1e6 + 1;
	using namespace std;

	int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
	int cap[MAXM], to[MAXM], nxt[MAXM];

	int score[40], lf[40];

	void init() {
	memset(first, -1, sizeof first);
	ned = 0;
	}

	void add(int u, int v, int f) {
		to[ned] = v, cap[ned] = f;
		nxt[ned] = first[u];
		first[u] = ned++;
		
		to[ned] = u, cap[ned] = 0;
		nxt[ned] = first[v];
		first[v] = ned++;
	}

	int dfs(int u, int f, int t) {
		if (u == t) return f;
		for(int &e = work[u]; e != -1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] == dist[u] + 1 && cap[e] > 0) {
				int df = dfs(v, min(f, cap[e]), t);
				if (df > 0) {
					cap[e] -= df;
					cap[e^1] += df;
					return df;
				}
			}
		}
		return 0;
	}

	bool bfs(int s, int t) {
		memset(&dist, -1, sizeof dist);
		dist[s] = 0;
		int st = 0, en = 0;
		q[en++] = s;
		while (en > st) {
			int u = q[st++];
			for(int e = first[u]; e!=-1; e = nxt[e]) {
				int v = to[e];
				if (dist[v] < 0 && cap[e] > 0) {
					dist[v] = dist[u] + 1;
					q[en++] = v;
				}
			}
		}
		return dist[t] >= 0;
	}

	int dinic(int s, int t) {
		int result = 0, f;
		while (bfs(s, t)) {
			memcpy(work, first, sizeof work);
			while (f = dfs(s, INF, t)) result += f;
		}
		return result;
	}

	int main() {
		fastio;
		int t; cin >> t;	
		while(t--){
			int n; cin >> n;
			vi ans;
			ms(score, 0);
			ms(lf, 0);
			vii matches;
			frr(i, n){
				string s; cin >> s;
				fr(j, n){
					if(s[j] == '1') score[i] += 2;
					else if(s[j] == 'd') score[i]++;
					else if(i < j + 1 && s[j] == '.') matches.pb({i, j+1}), lf[i]++;
					else if(s[j] == '.') lf[i]++;
				}
			}
			frr(i, n){
				bool deu = true;
				init();
				score[i] += lf[i]*2;
				int qnt = 0;
				for(auto p: matches){
					if(p.first != i && p.second != i){
						add(0, ++qnt + n, 2);
						add(qnt + n, p.first, 2);
						add(qnt + n, p.second, 2);
					}
				}
				qnt++;
				frr(j, n){
					if(j == i) continue;
					if(score[i] - score[j] < 0){
						deu = false;
						break;
					}
					add(j, qnt + n, score[i] - score[j]);
				}
				score[i] -= lf[i]*2;
				if(!deu) continue;
				if(dinic(0, qnt+n) == 2*qnt - 2) ans.pb(i);
			}
			vp(ans);
		}
	}	


