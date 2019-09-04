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
int n,m;
long double dist[1010];
vector<pair<int,long double>> adj[1010];

bool bf() {

  frr(j,n)
    dist[j] = 500000000.0;
  dist[1] = 0.0;

  fr(i,n-1)
    frr(j,n)
      for (auto x : adj[j])
        if (dist[x.fst] > dist[j] + x.snd)
          dist[x.fst] = dist[j] + x.snd;

  // frr(i,n)
  //   dbg(dist[i]);

  frr(j,n)
    for(auto x : adj[j])
      if(dist[x.fst] > dist[j] + x.snd)
        return true;

  return false;
}

int main(){
	fastio;
  cin>>n>>m;

  int a,b;
  long double c;

  fr(i,m) {
      cin>>a>>b>>c;
      adj[a].pb({b, -log10(c)});
  }

  if(bf())
    cout<<"inadmissible"<<endl;
  else
    cout<<"admissible"<<endl;

}
