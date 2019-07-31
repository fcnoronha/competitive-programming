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

int n,m,k;
vi sp;
vector<pii> adj[10100];

int dist[10100];

void dijsktra(int fonte){
    set<pii> fila;
    fila.insert({0,fonte});

    pii aux;
    while(!fila.empty()){
        aux=*fila.begin();
        fila.erase(fila.begin());

        if(dist[aux.snd]!=-1)
            continue;

        dist[aux.snd]=aux.fst;

        for(auto x : adj[aux.snd]){
            if(dist[x.fst]!=-1)
                continue;

            fila.insert({aux.fst+x.snd,x.fst});
        }
    }
}

bool bfs(int fonte){
    bool vis[10100];
    ms(vis,0);

    queue<int> fila;
    fila.push(fonte);

    int aux;
    while(!fila.empty()){

        aux=fila.front();
        fila.pop();

        if(vis[aux]==1)
            continue;

        vis[aux]=1;
        int cnt=0;

        for(auto x:adj[aux]){
            if((dist[x.fst]+x.snd)==dist[aux]){
                cnt++;
                if(vis[x.fst]==0)
                    fila.push(x.fst);
            }
        }
        if(cnt>1)
            return true;
    }

    return false;

}

int main(){
    fastio
    cin>>n>>m>>k;

    int x;
    fr(i,k){
        cin>>x;
        sp.pb(x);
    }

    int a,b,c;

    fr(i,m){
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }

    ms(dist,-1);

    dijsktra(1);

    if(bfs(n))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
}
