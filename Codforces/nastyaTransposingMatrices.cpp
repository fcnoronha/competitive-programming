// codeforces.com/contest/1136/problem/C

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

vi a[25000];
vi b[25000];

int main(){
	fastio

	int n, m;
	cin >> n >> m;


	int x;
	fr(i, n){
		fr(j, m){

			cin >> x;
			a[i+j].pb(x);
		}
	}

	fr(i, n){
		fr(j, m){

			cin >> x;
			b[i+j].pb(x);
		}
	}

	bool dale = 1;
	fr(i, 25000){
		sort(all(a[i]));
		sort(all(b[i]));

		if (a[i] != b[i]) dale = 0;
	}

	cout << (dale ? "YES" : "NO") << endl;
}
