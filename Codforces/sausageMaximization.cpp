// codeforces.com/contest/282/problem/E

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

#define MAXN 4000360 

int trie[MAXN][2];
int amt[MAXN];
ll val[MAXN];

int cnt = 1; 

void add(string str, int idx, int node, ll v){

	amt[node]++;

	if (str.length() == idx){
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

ll search(string str, int idx, int node){

	if (idx == str.length()){
		return val[node];
	}

	int aux = ((str[idx]-'0')+1)%2; 

	int &lidx = trie[node][aux];
	if (amt[lidx] > 0)
		return search(str, idx+1, lidx);
	
	aux++; aux %= 2;

	return search(str, idx+1, trie[node][aux]);
}

int main(){
	fastio
	
	// Init
	trie[0][0] = trie[0][1] = -1;

	int n;
	cin >> n;

	ll a[n+2];
	frr(i, n) cin >> a[i];
	a[0] = a[n+1] = 0ll;

	vl xorac; // XOR acumulated
	ll ac = 0ll;

	bitset<40> aux(ac);
	string stra = aux.to_string();
	add(stra, 0, 0, ac);

	for (int i = n+1; i > 0; i--){
		ac ^= a[i];
		xorac.pb(ac);
	}

	ll ans = 0;
	ac = 0ll;
	fr(i, n+1){

		ac ^= a[i];
		bitset<40> bt(ac);
		string str = bt.to_string();

		add(str, 0, 0, ac);

		ll v = xorac.back();
		xorac.pop_back();
		bitset<40> btw(v);
		string strw = btw.to_string();

		ll s = search(strw, 0, 0);

		ans = max(ans, s^v);
	}

	cout << ans << endl;
}