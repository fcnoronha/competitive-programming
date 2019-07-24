#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

int main(){

	fastio;

	int t;
	cin >> t;

	while (t--) {
		ll n, m, k;
		cin >> n >> m >> k;

		string a, b;
		cin >> a >> b;

		vi freq(26, 0);
		ll memo[26][26];
		ms(memo, 0);
		bool flag[26][26];
		ms(flag, 0);

		reverse(all(b));
		fr(i, m){
			freq[b[i]-'a']++;
			fr(j, 26)
				memo[b[i]-'a'][j] += freq[j];
		}

		k--;
		ll ans = 0, i = 0;
		while (i + k < n){
			char aux1 = a[i];
			char aux2 = a[i+k];

			if (flag[aux1-'a'][aux2-'a']){
				i++;
				continue;
			}
			flag[aux1-'a'][aux2-'a'] = 1;

			ans += memo[aux1-'a'][aux2-'a'];
			i++;	
		}	

		cout << ans << endl;
	}
}