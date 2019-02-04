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
bool amt[MAXN];

int cnt = 1; 

void add(string str, int idx, int node){

	amt[node]++;

	if (str.length() == idx)
		return;
	

	int &lidx = trie[node][ str[idx]-'0' ];
	if (lidx == -1){

		lidx = cnt;

		isEnd[cnt] = false;
		for (int l = 0; l < 2; l++)
			trie[cnt][l] = -1;

		cnt++;
		add(str, idx+1, cnt-1);
	}

	else 
		add(str, idx+1, lidx);
}

int search(string str, int idx, int node){

	if (idx == str.length())
		return true;

	int &lidx = trie[node][ str[idx]-'a' ];
	// Not found
	if (lidx == -1)
		return false;

	return search(str, idx+1, lidx);
}

void del(string str, int idx, int node){

	amt[node]--;

	if (idx == str.length())
		return 

	int &lidx = trie[node][ str[idx]-'0' ];
	search(str, idx+1, lidx);
}

int main(){
	fastio
	
	int q;
	cin >> q;

	multiset<int> ms;

	for (int i = 0; i < 2; i++)
		trie[0][i] = -1;

	bitset<30> z(0);
	string zero = z.to_string();
	add(zero, 0, 0);

	while (q--){

		char op;
		int x;

		cin >> op >> x;

		if (op == '+')
			ms.insert(x);

		else if (op == '-'){
			// Deletes only 1 element from multiset
			auto it = ms.find(x);
			ms.erase(it);
		}

		else {

			bitset<30> bt(x);
			// Getting bit representation
			string str = bt.to_string();

		}
	}

	// TODO: add to the trie when add to multiset
	//		 Store the number saved when reach end of str
	// 		 Search the follwing way: try to go to the positition
	// that is oposite of mine (mine+1%2) if amt > 0, retrieve 
	// number stored in the final position
}
