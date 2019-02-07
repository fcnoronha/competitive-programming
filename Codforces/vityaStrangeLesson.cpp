//codeforces.com/contest/842/problem/D

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


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

#define MAXN 2097152

int trie[MAXN][2];
int amt[MAXN];
int val[MAXN];
int mxamt[MAXN];

int cnt = 1; 

void add(int str, int idx, int node, int v, int a){

	amt[node] += a;

	if (21 == idx){
		val[node] = v;
		return;
	}

	int &lidx = trie[node][ ((str&(1 << (20-idx))) != 0) ];
	if (lidx == 0)
		lidx = cnt++;

	add(str, idx+1, lidx, v, a);
}

int search(int str, int idx, int node, int ans){

	if (idx == 21)
		return ans;
	
	int aux = ((str&(1 << (20-idx))) != 0); 
	int lidx = trie[node][aux];

	if (amt[lidx] < (1 << (20-idx)) || lidx == 0){

		if (amt[lidx] == 0 || lidx == 0) 
			return ans;

		return search(str, idx+1, lidx, ans);
	}

	aux = 1 - aux;

	if (aux)
		ans |= (1<<(20-idx));
	else
		ans ^= (1<<(20-idx));

	if (amt[trie[node][aux]] == 0 || trie[node][aux] == 0)
		return ans;

	return search(str, idx+1, trie[node][aux], ans);
}

int main(){
	fastio

	int n, q;
	cin >> n >> q;

	set<int> s;

	fr(i, n){
		int x;
		cin >> x;

		if (s.find(x) == s.end()) {
			add(x, 0, 0, x, 1);
			s.insert(x);
		}
	}

	int query = 0;
	fr(i, q){
		int aux;
		cin >> aux;

		query ^= aux;

		int ans = search(query, 0, 0, query);

		cout << (ans^query) << endl;
	}
}