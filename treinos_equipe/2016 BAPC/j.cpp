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


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

const int MAXN = 100100;
const int MAXM = 1001000;

int ned;
int dist[MAXN],first[MAXN],work[MAXN];
int to[MAXM], cap[MAXM], nxt[MAXM];

void init(){
  ned=0;
  memset(first,-1,sizeof first);
}

int add(int u, int v, int f){

  to[ned]=v;
  cap[ned]=f;
  nxt[ned]=first[u];
  first[u]=ned++;

  to[ned]=u;
  cap[ned]=0;
  nxt[ned]=first[v];
  first[v]=ned++;

}

int dfs(int u, int s, int t, int f){
  if(u==t)  return f;
  int v,df;
  for(int& e=work[u];e!=-1;e=nxt[e]){
    v=to[e];
    if(cap[e]>0 && dist[v]==1+dist[u]){
      df=dfs(v,s,t,min(f,cap[e]));
      if(df>0){
        cap[e]-=df;
        cap[e^1]+=df;
        return df;
      }
    }
  }
  return 0;
}

bool bfs(int s, int t){
  memset(dist,-1,sizeof dist);
  int u,v;
  dist[s]=0;
  queue<int> q;q.push(s);
  while(!q.empty()){
    u=q.front();q.pop();
    for(int e=first[u];e!=-1;e=nxt[e]){
      v=to[e];
      if(dist[v]==-1 && cap[e]>0){
        dist[v]=1+dist[u];
        q.push(v);
      }
    }
  }
  return dist[t]>=0;
}

int dinic(int s, int t){
  int df,result;
  result=0;
  while(bfs(s,t)){
    memcpy(work,first,sizeof work);
    while(df=dfs(s,s,t,INF))
      result+=df;
  }
  return result;
}

int xs[110], ys[110], xi[110], yi[110];
    int n;

int manh(int i, int j){

  return abs(xs[i]-xi[j]) + abs(ys[i]-yi[j]);

}

bool check(int cota){

  init();

  int src = 0;
  int sink = 2*n+1;

  frr(i,n){
    add(src,i,1);
    add(i+n,sink,1);
  }

  frr(i,n){
    frr(j,n){
      if(manh(i,j)<=cota)
        add(i,n+j,1);
    }
  }

  return dinic(src,sink)==n;

}

int main(){

    fastio;


    cin >> n;

    frr(i,n){
      cin >> xs[i] >> ys[i];
    }

    frr(i,n){
      cin >> xi[i] >> yi[i];
    }

    int ini=0;
    int end=1e9;

    int best = INF;

    while(ini<=end){
      int mid = (ini+end)>>1;
      if(check(mid)){
        best=min(best,mid);
        end=mid-1;
      }
      else
        ini=mid+1;
    }

    cout << best << endl;

}
