//codeforces.com/problemset/problem/271/D

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

#define MAXN 3000000

map<int, int> trie[MAXN];
int nbad[MAXN];
string bads;
int cnt = 1, k, ans = 0; 

void add(string str, int idx, int node){

	if (node > 0 && bads[(str[idx-1]-'a')] == '0') nbad[node]++;

	if (str.length() == idx || nbad[node] > k)
		return;

	auto lidx = trie[node].find(str[idx]-'a');
	int ind = trie[node][ str[idx]-'a' ];

	if (lidx == trie[node].end()){
		trie[node][ str[idx]-'a' ] = cnt++;
		ind = cnt-1;
		// ms(trie[lidx], -1);
	}

	nbad[ind] = nbad[node];
	add(str, idx+1, ind);
}

void bfs(int node){

	if (node > 0 && nbad[node] <= k) ans++;

	if (nbad[node] > k) return;

	for (auto u : trie[node])
			bfs(u.s);
}

int main(){
	fastio

	// ms(trie[0], -1);

	string str;

	cin >> str >> bads >> k;

	fr(l, str.length())
		add(str, l, 0);			

	bfs(0);

	cout << ans << endl;
}