//codeforces.com/contest/1245/problem/D

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

typedef struct aresta{
    ll dis;
    ll u, v;
}t_aresta;

bool comp(t_aresta a, t_aresta b){ 
	return a.dis < b.dis; 
}

vector<t_aresta> aresta;

int id[2009];
int sz[2009];

vector<pii> cnt;
vi ps;

int find(int x){
    if(id[x] == x) return x;
    return id[x] = find(id[x]);
}

void join(int a, int b){    
    a = find(a);
    b = find(b);
    
    if (sz[a] < sz[b]) id[a] = b;
    else if (sz[b] < sz[a]) id[b] = a;
    else {
        id[a] = b;
        sz[b]++;
    }    
}

int main(){
    fastio;

    int n;
    cin >> n;

    pll pos[n];
    fr(i, n) cin >> pos[i].f >> pos[i].s;

    ll c[n], k[n];
    fr(i, n) cin >> c[i];
    fr(i, n) cin >> k[i];

    fr(i, n) {

        for (int j = i+1; j < n; j++) {

            ll dis = abs(pos[i].f-pos[j].f) + abs(pos[i].s-pos[j].s);
            dis = dis*(k[i]+k[j]);

            aresta.pb(t_aresta{dis, i, j});
        }
        aresta.pb(t_aresta{c[i], n, i});
    }
    
    fr(i, n+1) id[i] = i;

    sort(all(aresta), comp);

    ll ans = 0l;;
    for (auto a: aresta) {

        if (find(a.u) != find(a.v) ){
            join(a.u, a.v);  
            ans += a.dis;
            if (a.u == n) ps.pb(a.v+1);
            else cnt.pb({a.u+1, a.v+1});
        }        
    }
    
    p(ans);
    p((int)ps.size());
    pv(ps);
    p((int)cnt.size());
    for (auto c: cnt) cout << c.f << " " << c.s << endl;
}
