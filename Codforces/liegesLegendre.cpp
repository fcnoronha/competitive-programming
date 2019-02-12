// codeforces.com/problemset/problem/603/C

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

int aux[] = {0, 1, 0, 1, 2}; // Bases for odd K

int g(int a, int k){

	if (k%2 == 0){
		if (a == 1 || a == 2) return a;
		return (a%2)^1;
	}

	if (a < 5) return aux[a];
	if (a%2 == 1) return 0;
	if (g(a/2, k) == 1) return 2;
	return 1;
}

int main(){
	fastio
	
	int n, k;
	cin >> n >> k;

	int x, ans = 0;
	fr(i, n){
		cin >> x;
		ans ^= g(x, k);
	}

	if (ans) p(Kevin);
	else p(Nicky);
}
