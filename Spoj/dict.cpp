// www.spoj.com/problems/DICT/

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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

#define MAXN 500009

struct t
{
	string word;
	bool isWordEnd;
	int lts[26];
} trie[MAXN];

int cnt = 1; 
bool opa;

void add(string str, int idx, int node){

	if (str.length() == idx){
		trie[node].word = str;
		trie[node].isWordEnd = true;
		return;
	}

	int &lidx = trie[node].lts[ str[idx]-'a' ];

	if (lidx == -1){

		lidx = cnt;

		trie[cnt].isWordEnd = false;
		for (int l = 0; l <= 25; l++)
			trie[cnt].lts[l] = -1;

		cnt++;
		add(str, idx+1, cnt-1);
	}

	else 
		add(str, idx+1, lidx);
}

bool prt(int node, bool oi){

	opa = true;

	if (trie[node].isWordEnd && oi){
		cout << trie[node].word;
		cout << endl;
	}

	fr(i, 26){

		if (trie[node].lts[i] != -1){
			prt(trie[node].lts[i], true);
		}
	}
}

bool search(string str, int idx, int node){

	if (idx == str.length()){

		prt(node, false);
		return true;
	}

	int &lidx = trie[node].lts[ str[idx]-'a' ];

	if (lidx == -1)
		return false;

	return search(str, idx+1, lidx);
}
	
int main(){
	fastio
		
	for (int i = 0; i < 26; i++)
		trie[0].lts[i] = -1;

	int n;
	cin >> n;

	string pal[n];
	fr(i, n){
		cin >> pal[i];
		add(pal[i], 0, 0);
	}

	int k;
	cin >> k;

	string aux;
	frr(i, k){
		cin >> aux;
		cout << "Case #" << i << ":" << endl;

		opa = false;
		search(aux, 0, 0);

		if (!opa)
			cout << "No match." << endl;
	}
}
