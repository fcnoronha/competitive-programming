//codeforces.com/contest/1185/problem/A

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

int main(){
	fastio

	int pos[3], d;
	cin >> pos[0];
	cin >> pos[1];
	cin >> pos[2];
	cin >> d;

	sort(pos, pos+3);
	int ans = 0;
	ans += (d - (pos[1]-pos[0]))*((d - (pos[1]-pos[0])) > 0);
	ans += (d - (pos[2]-pos[1]))*((d - (pos[2]-pos[1])) > 0);

	cout << ans << endl;
}
