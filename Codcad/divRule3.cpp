// codcad.com/problem/71

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

	int im = 0, p = 0;
	for (int i = 0; i < n.length(); i += 2)
		im += n[i] - '0';

	for (int i = 1; i < n.length(); i += 2)
		p += n[i] - '0';

	int aux = abs(im-p);

	if (aux == 0 || aux%11 == 0) p(S);
	else p(N);

}
