// codeforces.com/contest/923/problem/C

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

#define MAXN 9000600

int trie[MAXN][2];
int amt[MAXN];
int val[MAXN];

int cnt = 1; 

void add(string str, int idx, int node, int v){

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

int search(string str, int idx, int node){

	amt[node]--;

	if (idx == str.length()){
		return val[node];
	}
	
	int aux = (str[idx]-'0');
	int &lidx = trie[node][aux];
	if (amt[lidx] > 0)
		return search(str, idx+1, lidx);

	aux++; aux %= 2;

	return search(str, idx+1, trie[node][aux]);
}

int main(){
	fastio
	
	trie[0][0] = trie[0][1] = -1;	

	int n;
	cin >> n;

	int a[n];
	fr(i, n) cin >> a[i];

	fr(i, n){
		int x;
		cin >> x;

		bitset<30> bt(x);
		string str = bt.to_string();
		add(str, 0, 0, x);
	}

	fr(i, n){

		bitset<30> bt(a[i]);
		string str = bt.to_string();

		int s = search(str, 0, 0);
		cout << (a[i]^s) << " \n"[i == n-1];
		// del(str, 0, 0);
	}
}
