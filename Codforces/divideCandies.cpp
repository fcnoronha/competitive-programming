// https://codeforces.com/contest/1056/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(long long int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	ll a, b, ans=0;
	cin >> a >> b;
	ll k, h;
	fr(i, b){
		fr(j, b){
			if ((i*i + j*j)%b == 0){
				h = a/b + (a%b >= i && i > 0);
				k = a/b + (a%b >= j && j > 0);
				ans += (ll)(h*k);
			}
		}
	}
	cout << ans << endl;
}
