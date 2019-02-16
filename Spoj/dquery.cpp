//www.spoj.com/problems/DQUERY/

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

#define MAXQ 2000009
#define MAXN 300009

typedef struct{
	int f, s, i;
} hehe;

hehe q[MAXQ];
int a[MAXN];
int bsz;
int f[2000009];
int vans[MAXQ];

bool comp(hehe a, hehe b){

	if (a.f/bsz != b.f/bsz)
		return a.f/bsz < b.f/bsz;

	return a.s < b.s;
}

void mos(int n, int m){

	bsz = static_cast<int>(floor(sqrt(n)));

	sort(q, q+m, comp);

	int cr = 0, cl = 0, ans = 0;

	fr(i, m){

		int l = q[i].f;
		int r = q[i].s;

		// dbg(l);

		while (cl < l){
			f[a[cl]]--;
			//f[a[cl]] = max(0, f[a[cl]]);
			if (f[a[cl]] == 0) ans--;
			cl++;
			//dbg(cl);
		}

		while (cl > l){
			cl--;
			f[a[cl]]++;
			if (f[a[cl]] == 1) ans++;
			// dbg(cl);
		}

		while (cr <= r){
			f[a[cr]]++;
			if (f[a[cr]] == 1) ans++;
			cr++;
			// dbg(cl);
		}

		while (cr > r+1){
			cr--;
			f[a[cr]]--;
			if (f[a[cr]] == 0) ans--;
		}

		vans[q[i].i] = ans;
	}
}

int main(){
	fastio
	
	int n, m;
	scanf("%d", &n);

	frr(i, n) scanf("%d", &a[i]);

	scanf("%d", &m);
	fr(i, m) scanf("%d %d", &q[i].f, &q[i].s), q[i].i = i;

	mos(n, m);
	fr(i, m) printf("%d\n", vans[i]);
}
