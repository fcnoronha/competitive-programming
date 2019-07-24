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

int id[100009], sz[100009];

int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}


int main(){
	fastio

	int n, q;
	cin >> n >> q;

	fr(i, n+10) id[i] = i, sz[i] = 1;

	unordered_map<string, int> m;
	string s[n+10];

	frr(i, n) {
		cin >> s[i];
		m[s[i]] = i;
	}

	fr(i, q) {
		int op;
		string s1, s2;

		cin >> op >> s1 >> s2;

		if (op == 1) uni(m[s1], m[s2]);
		else {
			if (find(m[s1]) == find(m[s2])) cout << "yes\n";
			else cout << "no\n";
		}
	}
}
