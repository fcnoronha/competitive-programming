//www.spoj.com/problems/PHONELST/

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

#define MAXN 200009 

int trie[MAXN][10];
bool isEnd[MAXN]; 

int cnt = 1; 
bool da;

void add(string str, int idx, int node){

	if (str.length() == idx){
		if (isEnd[node] || node != cnt-1) da = false; 
		isEnd[node] = true;
		return;
	}

	if (isEnd[node]) da = false;

	//cout << trie[node].isWordEnd << " " << str[idx] << " " << node << endl;

	int &lidx = trie[node][ ((str[idx]-'0')) ];

	if (lidx == -1){

		lidx = cnt;

		for (int l = 0; l < 10; l++)
			trie[cnt][l] = -1;

		cnt++;
		add(str, idx+1, cnt-1);
	}

	else 
		add(str, idx+1, lidx);
}
	
int main(){

	int t;
	cin >> t;

	while (t--){

		int n;
		cin >> n;

		da = true;
		cnt = 1;

		ms(trie, -1);
		ms(isEnd, 0);

		fr(i, n){
			string pal;
			cin >> pal;
			add(pal, 0, 0);
		}

		if (da) p(YES);
		else p(NO);
	}
}