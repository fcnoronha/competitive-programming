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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int main(){
	fastio;

  ll n, d, k;
  cin >> n >> d >> k;

  pair<ll, string> v[n];
  fr(i, n)
    cin >> v[i].snd >> v[i].fst;

  sort(v, v+n);
  reverse(v, v+n);

  ll cnt = 0ll;
  fr(i, min(k, n)) {
    cnt += v[i].fst;

    if (cnt >= d) {

      cout << i+1 << '\n';
      fr(j, i+1)
        cout << v[j].snd << ", YOU ARE FIRED!\n";

      return 0;
    }
  }

  cout << "impossible\n";
}
