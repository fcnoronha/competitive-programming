#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tsts(t) rvr(t); while(t--)

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

#define MAXN 111110
#define MAXM 333330


int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

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
	init();
    rvr(n);
    int idd = 0;
    map<ll, int> id;
    vii pair;
    frr(i, n){
        rvr(a); rvr(b);
        pair.pb(mp(a, b));
        if(id[a+b] == 0) id[a+b] = ++idd;
        if(id[a-b] == 0) id[a-b] = ++idd;
        if(id[(ll)a*(ll)b] == 0) id[(ll)a*(ll)b] = ++idd;
        add(i, n+1+id[a+b], 1);
        add(i, n+1+id[a-b], 1);
        add(i, n+1+id[(ll)a*(ll)b], 1); 
    }
    frr(i, n) add(0, i, 1);
    for(auto p: id){
        add(p.ss+n+1, n+1, 1);
    }
    int ans = dinic(0, n+1);
    if(ans == n){
        fr(i, n){
            if(cap[6*i] == 0){
                printf("%d + %d = %d\n", pair[i].ff, pair[i].ss, pair[i].ss + pair[i].ff);
            }
            else if(cap[6*i + 2] == 0){
                printf("%d - %d = %d\n", pair[i].ff, pair[i].ss, -pair[i].ss + pair[i].ff);
            }
            else{
                printf("%d * %d = %lld\n", pair[i].ff, pair[i].ss, (ll)pair[i].ff*(ll)pair[i].ss);
            }
        }
    }
    else printf("impossible\n");

}