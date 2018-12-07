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
#define olar cout << "olar" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll memo[1000011], ac[29];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	fr(i, 1000000){
		string s = to_string(i);
		while (s.length() < 6)
			s = "0" + s;	
		
		int d = abs(s[0]+s[1]+s[2]-s[3]-s[4]-s[5]);

		fr(j, d)
			memo[i] += ac[j];

		ac[d]++;
	}

	int n;
	cin >> n;
	fr(i,n){
		int a;
		cin >> a;
		cout << memo[a] << endl;
	}

}