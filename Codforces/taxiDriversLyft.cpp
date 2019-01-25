//codeforces.com/contest/1075/problem/B

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
	
	int n, m;
	cin >> n >> m;

	vector<pii> pos(n+m, {0, INT_MAX}); // pos - dist to taxi
	vi isTaxi(n+m, 0);
	vi caller(n+m, INT_MAX);

	map<int,int> tta; // taxi to ans
	int cnta = 0;

	fr(i, n+m) cin >> pos[i].f;
	fr(i, n+m){
		int x;
		cin >> x;
		if (x){
			isTaxi[i] = 1;
			tta[i] = cnta++;
		}
	}

	fr(i, n+m){

		if (!isTaxi[i]) continue;

		int auxi = i - 1;
		while (auxi >= 0){

			if (isTaxi[auxi])
				break;

			int auxd = pos[i].f - pos[auxi].f;
			if (auxd < pos[auxi].s){
				pos[auxi].s = auxd;
				caller[auxi] = i;
			}

			else
				break;

			auxi--;
		}

		auxi = i + 1;
		while (auxi < n+m){

			if (isTaxi[auxi])
				break;

			int auxd = pos[auxi].f - pos[i].f;
			if (auxd < pos[auxi].s){
				pos[auxi].s = auxd;
				caller[auxi] = i;
			}

			else 
				break;

			auxi++;
		}
	}

	//fr(i, n+m) dbg(caller[i]);

	int ant = -1, cnt = 0;
	vi ans(m, 0);
	fr(i, m+n){

		if (caller[i] == INT_MAX) continue;

		if (ant == -1){
			ant = caller[i];
			cnt++;
		}

		else if (ant == caller[i]) cnt++;

		else {
			ans[tta[ant]] = cnt;
			cnt = 1;
			ant = caller[i];
		}
	}
	if (cnt) ans[tta[ant]] = cnt;
	
	fr(i, m) cout << ans[i] << " \n"[i == m-1];
}
