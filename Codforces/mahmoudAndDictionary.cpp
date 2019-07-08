//codeforces.com/problemset/problem/766/D

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

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define maxn 500009

int id[maxn], sz[maxn];
int n, m, q;

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

	/*
		The ideia behind this problem is to use union find in the following way:
		each word will have a unique value for it and a unique value for its
		'inverse', in my solution the real value of the word is the one that is
		associeted in the mapping loop (val) and its inverse value is equal val+
		cnt, where cnt will be the total number of words.

		Now, to make relations, I just play with these two mapped-values. A
		synonymy relation will be value1-value2 and an antonymy relation will
		be (value1+cnt)-value2 && value1-(value2+cnt).
	*/

	fr(i, maxn-2) id[i] = i, sz[i] = 1;

	cin >> n >> m >> q;

	int cnt = 0, op;
	map<string, int> pal;
	string s1, s2;

	fr(i, n) {

		cin >> s1;

		// mapping words into integers
		pal[s1] = cnt++;
	}

	bool ans1[m];
	fr(i, m) {

		cin >> op >> s1 >> s2;

		int val_1 = pal[s1], val_2 = pal[s2];

		// synonymy
		if (op == 1) {

			// check if relation is invalid
			if (find(val_1) == find(val_2+cnt) || find(val_1+cnt) == find(val_2)) {
				ans1[i] = false;
				continue;
			}

			ans1[i] = true;
			// creating synonymy relation
			uni(val_1, val_2);
			uni(val_1+cnt, val_2+cnt);
			continue;
		}

		// antonymy
		if (find(val_1) == find(val_2) || find(val_1+cnt) == find(val_2+cnt)) {
			ans1[i] = false;
			continue;
		}

		// creating antonymy relation
		ans1[i] = true;
		uni(val_1+cnt, val_2);
		uni(val_2+cnt, val_1);
	}

	int ans2[q];
	fr (i, q) {

		cin >> s1 >> s2;
		int val_1 = pal[s1], val_2 = pal[s2];

		if (find(val_1) == find(val_2))
			ans2[i] = 1;
		else if (find(val_1) == find(val_2+cnt) || find(val_1+cnt) == find(val_2))
			ans2[i] = 2;
		else
			ans2[i] = 3;
	}

	fr (i, m) {
		if (ans1[i]) p("YES");
		else p("NO");
	}

	fr (i, q)
		p(ans2[i]);
}
