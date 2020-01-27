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

vector<pii> vec;

set<pii> adj[1111];
int aa[5009], ans[5009];

int main(){
    int n, m; scanf("%d%d", &n, &m);
    fr(i, n){
        int a; scanf("%d", &a);
        vec.pb({a, i});
    }
    sort(all(vec));
    fr(i, m){
        scanf("%d", &aa[i]);
    }
    fr(i, m){
        int r; scanf("%d", &r);
        adj[aa[i]].insert({r, i});
    }
    for(int i = n - 1; i >= 0; i--){
        int idx = -1, mincur = 2e3 + 1;
        for(int j = vec[i].first; j <= 1000; j++){
            if(!adj[j].empty()){
                if(mincur < (*adj[j].begin()).first) continue;
                idx = j, mincur = (*adj[j].begin()).first;
            }
        }
        if(idx == -1){
            printf("impossible\n");
            return 0;
        }
        else{
            ans[vec[i].second] = (*adj[idx].begin()).second;
            adj[idx].erase(adj[idx].begin());
        }
    }
    fr(i, n){
        printf("%d%c", ans[i]+1, " \n"[i==n-1]);
    }
}
