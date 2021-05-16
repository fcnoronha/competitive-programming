#include <bits/stdc++.h>
using namespace std;
     
typedef long long ll;
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args);
#endif

const int maxn = 20000;
int id[maxn];
int sz[maxn];

void init(int n) {
    for (int i = 1; i<=n; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}
int find(int x) {
    if ( x == id[x]) return x;
    return id[x] = find(id[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a==b) return;
    if (sz[a] > sz[b]) {
        id[b] = a;
        sz[a] += sz[b];
    } else {
        id[a] = b;
        sz[b] += sz[a];
    }
}

map<pair<int,int>, int> ans;

vector<pair<int,int> > adj[maxn];

void dfs(int x, int pa, int org, int z) {
    for (auto edg : adj[x]) {
        int y = edg.first;
        int k = edg.second;
        if (y != pa) {
            ans[make_pair(org,y)] = min(z,k);
            dfs(y, x, org, min(z,k));
        }
    }
}

int n,m;


int bot;

ll kruskall(vector<pair<int,pair<int,int> > >& arestas, int v ) {
    init(n);
    vector<pair<int,pair<int,int> > > mst;
    for (int i = 0; i<arestas.size(); i++) {
        int a = arestas[i].second.first;
        int b = arestas[i].second.second;
        int k = arestas[i].first;
        if (find(a) != find(b)) {
        
            unite(a,b);
            mst.push_back(arestas[i]);
        }
    }
    bot = max(bot, mst.back().first);
    ll total = 0;
    if (v == 1) {
        init(n);
        reverse(mst.begin(), mst.end());
        for (int i = 0; i<mst.size(); i++) {
            int a = mst[i].second.first;
            int b = mst[i].second.second;
            int k = mst[i].first;
            if (find(a) != find(b)) {
                total += sz[find(a)] * 1ll * sz[find(b)] * k;
                unite(a,b);
            }
        }
    }
    return total;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    bot = -50;
    vector<pair<int,pair<int,int> > > arestas;
    for (int i = 0; i<m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        arestas.push_back(make_pair(k,make_pair(a,b)));
    }
    sort(arestas.begin(), arestas.end());
    reverse(arestas.begin(), arestas.end());
    kruskall(arestas, 0);
    vector<pair<int,pair<int,int> > > newAr;
    reverse(arestas.begin(), arestas.end());
    for (int i = 0; i<m; i++) {
        int a = arestas[i].second.first;
        int b = arestas[i].second.second;
        int k = arestas[i].first;
        if (k >= bot) {
            newAr.push_back(arestas[i]);
        }
    }
    ll a = kruskall(newAr, 1);
    cout << a << endl;
}