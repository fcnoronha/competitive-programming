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

ll memo[300300][11];
ll v[330330];
int n,m;

ll pd(int ind, int charge){

  if(ind>n)
    return 0;

    ll &pdm = memo[ind][charge];
    if(pdm!=-1) return pdm;

    pdm=pd(ind+1, min(charge+1,m));

    if(charge==m)
      pdm=max(pdm, v[ind] + pd(ind+1,1));

    return pdm;

}

int main(){

	fastio;

  cin >> n >> m;

  frr(i,n)
    cin >> v[i];

  ms(memo,-1);

  cout << pd(1,0) << endl;

}
