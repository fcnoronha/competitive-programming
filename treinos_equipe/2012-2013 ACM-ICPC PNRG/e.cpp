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

int id[200];
int sz[200];

vi adj[1010];
//
// int find(int a){
//     if(a==id[a])    return a;
//     return id[a]=find(id[a]);
// }
//
// void join(int a, int b){
//     a=find(a);b=find(b);
//     if(a==b)    return;
//     if(sz[a]<sz[b]) swap(a,b);
//     id[b]=a;
//     sz[a]+=sz[b];
// }
//
// int vis[1010];
// vi topsort;
//
// void topdfs(int v){
//     vis[v]=1;
//     topsort.pb(v);
//     for(auto x : adj[v]){
//         if(vis[x])  continue;
//         dfs(x);
//     }
// }
//
// void dfs(int v, int from){
//     join(v,from);
//     vis[v]=1;
//     for(auto x : adj[v]){
//         if(vis[x])  continue;
//         dfs(x);
//     }
// }

int main(){

    fastio;
    int g; cin >> g;

    frr(i,g){

        int ring,rune;
        bool nullError = false;
        bool missError = false;
        bool repeatError = false;
        cin >> ring >> rune;

        vector<tuple<int,int,int>> statements;

        frr(j,rune){

            int r1,r2,r3;
            int troll;
            cin >> r1 >> r2 >> r3 >> troll;

            if(!r1 || !r2 || !r3)
                nullError = true;

            if(abs(r1)>ring || abs(r2)>ring || abs(r3)>ring)
                missError=true;

            set<int> lol;
            lol.insert(abs(r1));
            lol.insert(abs(r2));
            lol.insert(abs(r3));

            if(lol.size()!=3)
                repeatError=true;

            statements.pb(make_tuple(r1,r2,r3));

        }

        if(nullError){
            cout << "INVALID: NULL RING" << endl;
            continue;
        }
        if(missError){
            cout << "INVALID: RING MISSING" << endl;
            continue;
        }
        if(repeatError){
            cout << "INVALID: RUNE CONTAINS A REPEATED RING" << endl;
            continue;
        }

        bool sat = false;

        fr(mask,1<<ring){

            bool aux = true;

            for(auto cara : statements){

                int f1=true,f2=true,f3=true;

                int x1 = get<0>(cara);
                if(x1<0)    f1=false;

                int x2 = get<1>(cara);
                if(x2<0)    f2=false;

                int x3 = get<2>(cara);
                if(x3<0)    f3=false;

                x1 =abs(x1)-1;
                x2=abs(x2)-1;
                x3=abs(x3)-1;

                x1=(1<<x1)&mask;
                x2=(1<<x2)&mask;
                x3=(1<<x3)&mask;

                if(x1)  x1=1;
                if(x2)  x2=1;
                if(x3)  x3=1;

                bool can = false;

                if(x1==f1 || x2==f2 || x3==f3)
                    can=true;

                aux&=can;

            }

            sat|=aux;

        }

        cout << (sat ? "RUNES SATISFIED!" : "RUNES UNSATISFIABLE! TRY ANOTHER GATE!") << endl;

    }
}
