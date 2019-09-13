#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define fst first
#define snd second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ll n,m,x;
ll dist[11234];
vector<pll> adj[11234];

ll dijkstra( ll max_edj) {
  ms(dist,-1);
  set<pll> fila;
  fila.insert({0,1});

  pll aux;
  while (!fila.empty()){
    aux = *fila.begin();
    fila.erase(fila.begin());

    ll dst = aux.fst;
    ll v = aux.snd;

    if (dist[v] != -1)
      continue;
    dist[v] = dst;

    for (auto x : adj[v]) {
      if (dist[x.snd] != -1)
        continue;
      if (x.fst <= max_edj){
        fila.insert({dst + x.fst, x.snd});
      }
    }
  }
  return dist[n];
}

vector<ll> edj;

int main(){
    fastio;
    cin>>n>>m>>x;

    ll a,b,c;
    fr(i,m) {
      cin>>a>>b>>c;
      adj[a].pb({c,b});
      adj[b].pb({c,a});
      edj.pb(c);
    }

    sort(all(edj));

    ll sp = dijkstra(edj[edj.size()-1]);
    ll n_dst = sp;
    n_dst += (sp*x)/100;

    int ini,fim,meio;
    ll bst, val;

    bst = edj[edj.size()-1];
    ini = 0;
    fim = edj.size() - 1;

    while (ini <= fim) {
      meio = (ini + fim)/2;
      val = dijkstra( edj[meio]);

      if (val != -1 and val <= n_dst){
        bst = edj[meio];
        fim = meio - 1;
      }
      else
        ini = meio + 1;

    }

    cout<<bst<<endl;


}
