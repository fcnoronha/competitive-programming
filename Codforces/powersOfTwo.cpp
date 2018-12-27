// https://codeforces.com/contest/1095/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<ll> vi;

int main(){
	fastio
	
	ll n, k;
	cin >> n >> k;

	vi ans;

	ll aux = n, i = 30;
	while (aux > 0){
		if (aux - (1<<i) >= 0) ans.pb(1<<i), aux -= 1<<i;
		i--;
	}

	// for (auto u : ans) cout << u << " ";

	if (ans.size() > k){
		cout << "NO" << endl;
		return 0;
	}

	i = 0;
	while (ans.size() < k && i < ans.size()){
		aux = ans[i];
		if (aux == 1) i++;
		else{
			aux /= 2;
			ans[i] = aux;
			ans.pb(aux);
		}
	}

	if (ans.size() == k){
		cout << "YES" << endl;
		for (auto u : ans) cout << u << " ";
		cout << endl;
		return 0;
	}

	cout << "NO" << endl;
	return 0;
}
