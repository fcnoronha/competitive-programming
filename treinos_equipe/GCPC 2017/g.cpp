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

  ll ans = 0;
  int n;

  vector<pll> v;
  cin >> n;

  frr(i,n){
    pll aux;
    cin >> aux.fst >> aux.snd;
    v.pb(aux);
  }

  ll border = 0;
  ll area = 0;

  fr(i,n){
    pll from = v[i];
    pll to = v[(i+1)%n];
    ll dx = abs(from.fst - to.fst);
    ll dy = abs(from.snd - to.snd);
    area += from.fst*to.snd - from.snd*to.fst;
    border+=abs(__gcd(dx,dy));
  }

  area=abs(area);

  ans +=area;
  ans-=border;
  ans+=2;

  cout << ans/2ll << endl;

}
