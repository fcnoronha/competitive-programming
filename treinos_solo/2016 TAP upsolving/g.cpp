//www.spoj.com/problems/TAP2016G/

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

#define maxn 100003

vector<pii> adj[maxn];
int memo[maxn];
int n;

#define MAXN maxn*32 

int trie[MAXN][2];
int amt[MAXN];
int val[MAXN];

int cnt = 1; 

void add(string &str, int idx, int node, int v){

	amt[node]++;

	if (32 == idx){
		val[node] = v;
		return;
	}

	int &lidx = trie[node][ str[idx]-'0' ];
	if (lidx == -1){
		lidx = cnt++;
		trie[lidx][0] = trie[lidx][1] = -1;
	}

	add(str, idx+1, lidx, v);
}

int search(string &str, int idx, int node){

	if (idx == 32)
		return val[node];
	
	int aux = ((str[idx]-'0')+1)%2; 
	int &lidx = trie[node][aux];
	if (amt[lidx] > 0)
		return search(str, idx+1, lidx);

	aux++; aux %= 2;

	return search(str, idx+1, trie[node][aux]);
}

void dfs(int u, int mask, int prt) {

    bitset<32> z(mask);
	string number = z.to_string();
	add(number, 0, 0, mask);

    memo[u] = mask;

    for (auto v: adj[u]) 
        if (v.f != prt)
            dfs(v.f, mask^v.s, u);
}

int main(){
    fastio;

    int n;
    while (cin >> n) {

        cnt = 1;
        trie[0][0] = trie[0][1] = -1;

        frr(i, n) adj[i].clear();

        int a, b, c;
        fr(i, n-1) {
            cin >> a >> b >> c;
            adj[a].pb({b, c});
            adj[b].pb({a, c});
        }

        bitset<32> z(0);
        string zero = z.to_string();
        add(zero, 0, 0, 0);

        dfs(1, 0, 1);
        frr(i, n) {
            int x = memo[i];

            bitset<32> z(x);
            string number = z.to_string();
            p( (x^search(number, 0, 0)) );
        }
    }
}
