#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

typedef long long int ll;
const int INF =  0x3f3f3f3f;

ll n,c,t;
ll v[100100];

int main(){

	fastio;

	ll n; cin >> n;

	ll base = __builtin_popcountll(n);

	cout << (1ll<<base) << endl;

}