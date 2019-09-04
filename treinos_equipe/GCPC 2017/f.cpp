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

const int MAXN = 101000;
const int MAXM = 1001000;
const int INF = 0x3f3f3f3f;

int ned;
int first[MAXN], dist[MAXN], work[MAXN];
int nxt[MAXM], to[MAXM], cap[MAXM];
int id[4000][4000];
int n, m, k;

void init() {
  ms(first,-1);
  ned = 0;
}

void add( int u, int v, int f) {

  id[u][v]=ned;

  to[ned] = v, cap[ned] = f;
  nxt[ned] = first[u];
  first[u] = ned++;

  to[ned] = u, cap[ned] = 0;
  nxt[ned] = first[v];
  first[v] = ned++;
}

int dfs( int u, int f, int s, int t) {
  if (u == t) return f;
  int df, v;

  for (int &e = work[u]; e != -1; e = nxt[e]) {
    v = to[e];
    if (dist[v] == dist[u] + 1 and cap[e] > 0) {
      df = dfs( v, min( f, cap[e]), s, t);
      if (df > 0) {
        cap[e] -= df;
        cap[e^1] += df;
        return df;
      }
    }
  }
  return 0;
}

bool bfs( int s, int t) {
  int u, v;
  ms( dist, -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    u = q.front();
    q.pop();

    for (int e = first[u]; e != -1; e = nxt[e]) {
      v = to[e];
      if (dist[v] < 0 and cap[e] > 0) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist[t] >=0;
}

int dinic( int s, int t) {
  int res = 0, f;
  while (bfs( s, t)) {
    memcpy( work, first, sizeof work);
    while (f = dfs( s, INF, s, t))
      res += f;
  }
  return res;
}

void zera(int v, int cost){

  //faz aresta indo do source ate a tomada ter cap cost
  cap[ id[0][v] ] = cost;
  cap[ id[0][v]^1 ]= 0;

  //para todas as arestas do meio, se tiver saturada dessatura ela e o aparelho
  for(int e = first[v]; e!=-1; e=nxt[e]){

    //ignora aresta reversa
    if(to[e]==0)
      continue;

    //cara eh o aparelho q eu vo visitar
    int cara = to[e];

    //se estou usando o aparelho
    if(cap[e]==0){

      //dessatura a aresta entre tomada e aparelho
      cap[e]=1;
      cap[e^1]=0;

      //dessatura aresta entre aparelho e sink

      cap[ id[cara][n+m+1] ]=1;
      cap[ id[cara][n+m+1]^1 ]=0;

    }
  }

}

int main(){

  fastio;
  init();

  //m sockets, n devices, k edges

  cin >> m >> n >> k;

  int src, snk;
  src = 0;
  snk = n + m + 1;

  int x, y;
  //x = socket, y = device
  fr(i,k){
    cin>>x>>y;
    add( x, y + m, 1);
  }

  frr(i,m)
    add( src, i, 1);

  frr(i,n)
    add( m + i, snk, 1);

  int mf = dinic( src, snk);

  for(int i=1;i<=m;i++){

    zera(i,3);

    dinic(src,snk);
    int ans = 0;

    for(int e=first[snk];e!=-1;e=nxt[e]){
      if(cap[e]==1)
        ans++;
    }

    mf=max(mf,ans);
    zera(i,1);

  }

  cout << mf << endl;

}
