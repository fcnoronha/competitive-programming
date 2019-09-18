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

ll memo[1010][1010];
vi adj[10100];
ll cost[10100],delay[10100];
int x,n,m,t;

ll pd(int tempo, int onde){

  if(tempo<0)
    return 1e15;

  if(onde==1 && tempo==delay[1]){
    return cost[1];
  }

  ll& pdm = memo[tempo][onde];
  if(pdm!=-1) return pdm;

  pdm=1e15;

  int new_time = tempo - delay[onde];

  for(auto x : adj[onde]){
    ll new_cost = cost[onde] + pd(new_time-t,x);
    pdm=min(pdm,new_cost);
  }

  pdm=min(pdm,pd(new_time,onde) + cost[onde]);

  return pdm;

}

int main(){

	fastio;

  cin >> x >> n >> m >> t;

  ms(memo,-1);

  frr(i,m){
    int a,b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  frr(i,n)
    cin >> delay[i] >> cost[i];

  ll ans = pd(x,1);
  if(ans>=1e15)
    cout << "It is a trap." << endl;
  else
    cout << ans << endl;

}
