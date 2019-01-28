// www.spoj.com/problems/PRIME1/

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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
	
	int t;
	cin >> t;

	while (t--){

		ll a, b;
		cin >> a >> b;

		for (int i = a; i <= b; i++){
			if (i == 1) i++;
			bool is = true;
			for (int d = 2; d*d <= i; d++){
				if (i%d == 0){
					is = 0;
					break;
				}
			}

			if (is) cout << i << endl;
		}

		if (t > 0) cout << endl;
	}
}
