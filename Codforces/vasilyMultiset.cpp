//codeforces.com/problemset/problem/706/D

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

#define MAXN 7000009 

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

		lidx = cnt;

		for (int l = 0; l < 2; l++)
			trie[cnt][l] = -1;

		cnt++;
		add(str, idx+1, cnt-1, v);
	}

	else 
		add(str, idx+1, lidx, v);
}

int search(string str, int idx, int node){

	if (idx == str.length()){
		return val[node];
	}

	int aux = ((str[idx]-'0')+1)%2; 
	// dbg(aux);
	int &lidx = trie[node][aux];
	if (amt[lidx] > 0){
		// dbg(amt[lidx]);
		return search(str, idx+1, lidx);
	}

	// p(oi);
	aux++; aux %= 2;

	return search(str, idx+1, trie[node][aux]);
}

void del(string str, int idx, int node){

	amt[node]--;

	if (idx == str.length())
		return;

	int &lidx = trie[node][ str[idx]-'0' ];
	del(str, idx+1, lidx);
}

int main(){
	fastio

	int q;
	cin >> q;

	for (int i = 0; i < 2; i++)
		trie[0][i] = -1;

	bitset<30> z(0);
	string zero = z.to_string();
	add(zero, 0, 0, 0);

	while (q--){

		char op;
		int x;

		cin >> op >> x;

		// Getting bit representation
		bitset<30> bt(x);
		string str = bt.to_string();

		if (op == '+')
			add(str, 0, 0, x);
		
		else if (op == '-')
			del(str, 0, 0);

		else {
			int s = search(str, 0, 0);
			cout << (s^x) << endl;
		}
	}
}
