// https://codeforces.com/contest/1080/problem/B

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
typedef vector<int> vi;

int main(){
	ll n, a, b;
	long double	 ans;

	cin >> n;

	fr(i, n){
		cin >> a >> b;
		a = a*pow(-1, a%2);
		b = b*pow(-1, b%2);
		ans = ((b + a)/2.0);
		if (ans > 0) ans = ceil(ans);
		else ans = floor(ans);
		cout << (int)ans << endl; 
	}

}
