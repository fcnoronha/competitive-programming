#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct Trie {
	int cnt, word;
	map <char, Trie> m;

	Trie () {
		word = cnt = 0;
		m.clear();
	}

	void add (const string &s, int i) {
		cnt++;
		if (i == (int)s.size()) {
			word++;
			return;
		}

		if (!m.count(s[i]))
			m[s[i]] = Trie();

		m[s[i]].add(s, i + 1);
	}


	void add (const string &s) {
		add (s, 0);
	}


} T;

void go(){

	int n;
	cin >> n;

	Trie T = Trie();
	vector<string> v;

	fr(i,n){
		string s; cin >> s;
		T.add(s);
		v.pb(s);
	}

}

int main(){
	fastio

	int t; cin >> t;
	while(t--)	go();

}
