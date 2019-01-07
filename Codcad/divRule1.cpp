// codcad.com/problem/69

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

int main(){
	fastio
	
	string n;
	cin >> n;

	int ac = 0;
	fr(i, n.length()) ac += (n[i] - '0');

	int aux = n[n.length()-1] - '0';
	if (aux%2 == 0) p(S);
	else p(N);

	if (ac%3 == 0) p(S);
	else p(N);

	if (aux == 0 || aux == 5) p(S);
	else p(N);	
}
