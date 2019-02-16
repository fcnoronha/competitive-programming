//codeforces.com/contest/220/problem/B

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

#define MAXN 100009

typedef struct{
	int f, s, i;
} hehe;

hehe qry[MAXN];
int f[100009];
int a[MAXN], b[MAXN], vans[MAXN], c[MAXN];
int bsz;

map<int, int> m;

bool comp(hehe a, hehe b){

	if (a.f/bsz != b.f/bsz)
		return a.f/bsz < b.f/bsz;

	return a.s < b.s;
}

void mos(int n, int mq){

	bsz = static_cast<int>(floor(sqrt(n)));

	sort(qry, qry+mq, comp);

	int cr = 0, cl = 0, ans = 0;

	fr(i, mq){

		int l = qry[i].f;
		int r = qry[i].s;

		while (cl < l){
			f[a[cl]]--;
			if (f[a[cl]] == c[cl]-1) ans--;
			if (f[a[cl]] == c[cl]) ans++;
			cl++;
		}

		while (cl > l){
			cl--;
			f[a[cl]]++;
			if (f[a[cl]] == c[cl]) ans++;
			if (f[a[cl]] == c[cl]+1) ans--;
		}

		while (cr <= r){
			f[a[cr]]++;
			if (f[a[cr]] == c[cr]) ans++;
			if (f[a[cr]] == c[cr]+1) ans--;
			cr++;
		}

		while (cr > r+1){
			cr--;
			f[a[cr]]--;
			if (f[a[cr]] == c[cr]-1) ans--;
			if (f[a[cr]] == c[cr]) ans++;
		}

		vans[qry[i].i] = ans;
	}
}

int main(){
	
	int n, q;
	cin >> n >> q;

	frr(i, n){
		cin >> a[i];
		b[i] = c[i] = a[i];
	}

	sort(b, b+n);
	
	int cnt = 1;

	frr(i, n){
		if (i > 0 && b[i] == b[i-1]) continue;
		m[b[i]] = cnt++;
	}

	frr(i, n) a[i] = m[a[i]];

	fr(i, q) cin >> qry[i].f >> qry[i].s, qry[i].i = i;

	mos(n, q);

	fr(i, q) cout << vans[i] << endl;
}
