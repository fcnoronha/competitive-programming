// codeforces.com/contest/1091/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
#define p(x) cout << #x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio
	
	int n;
	cin >> n;

	ll a = 0, b = 0, aux1, aux2;

	fr(i, n) cin >> aux1 >> aux2, a += aux1, b += aux2;
	fr(i, n) cin >> aux1 >> aux2, a += aux1, b += aux2;

	a /= n;
	b /= n;

	cout << a << " " << b << endl;
}
