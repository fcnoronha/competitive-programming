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
const int N = 1e3 + 2;

int par[N], depth[N], prof[N], def[N];

set<int> adj[N];


int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;

}

int dfs(int v){
    if(prof[v]) return prof[v];
    prof[v] = 1;
    for(auto u: adj[v]){
        prof[v] = max(1 + dfs(u), prof[v]);
    }
    return prof[v];
}

void build(int v, int cur){
    if(def[v]) return;
    if(cur == prof[v]){
        def[v] = 1;
    }
    else return;
    for(auto u: adj[v]){
        build(u, cur - 1);
    }
}


int main(){
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastio;
    int n, m; cin >> n >> m;
    vector<pii> S;
    ms(prof, 0);
    frr(i, n) par[i] = i;
    fr(i, m){
        string s; cin >> s;
        int j = 0, k = 0;
        bool first = true;
        char cc = 'a';
        fr(l, s.size()){
            if(s[l] - '0' < 0 || s[l]-'0' > 10){
                first = false;
                cc = s[l];
                continue;
            }
            if(first) j*=10, j+= s[l] - '0';
            else k *= 10, k +=s[l] - '0'; 
        }
        if(cc == '=') join(j, k);
        else if(cc == '>') S.pb({k, j});
        else S.pb({j, k});
    }
    for(auto p: S){
        adj[find(p.second)].insert(find(p.first));
    }
    frr(i, n){
        if(!prof[find(i)]){
            if(dfs(find(i)) == 3){
                build(find(i), 3);
            }
        }
    }
    string abc = "BRW";
    frr(i, n){
        if(def[find(i)]){
            cout << abc[prof[find(i)] - 1];
        }
        else cout << "?";
    }
    cout << endl;
}