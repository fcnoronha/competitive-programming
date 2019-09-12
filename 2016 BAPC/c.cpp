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

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
int c, p, x, l;
vector<int> adj[212345];
int freq[212345], at[212345];
bool vis[212345];

void bfs() {
  queue<int> fila;
  fila.push(l);
  vis[l] = 1;
  int aux;
  while (!fila.empty()) {
    aux = fila.front();
    fila.pop();

    for (auto x : adj[aux]) {
      if (vis[x])
        continue;
      at[x]++;
      if(at[x] >= (freq[x]+1)/2) {
        vis[x] = 1;
        fila.push(x);
      }
    }

  }
}

int main(){
    fastio;
    cin>>c>>p>>x>>l;

    int a, b;
    fr(i,p) {
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
      freq[a]++;
      freq[b]++;
    }
    bfs();

    if(vis[x])
      cout<<"leave"<<endl;
    else
    cout<<"stay"<<endl;

}
