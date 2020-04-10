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

#define maxn 1000009

const ll mod = 1000000007;
ll cat[maxn], fat[maxn+maxn];
    int n;

ll fastexp(ll b, ll e) {
    if (!e) return 1;
    ll ans = fastexp(b, e/2);
    ans = (ans*ans)%mod;
    if (e%2) ans = (ans*b)%mod;
    return ans;
}

ll invmod(ll b) {
    return fastexp(b, mod-2);
}

ll comb(ll a, ll b) {
    ll ret = fat[a];
    ll aux = (fat[b]*fat[a-b])%mod;
    ret = (ret*invmod(aux))%mod;
    return ret;

} 

vector<int> pos[maxn];
vi v;

int tree[maxn*4];

void build(int idx, int i, int j){
    if(i == j){
        tree[idx] = v[i];
        return; 
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

int qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l)
        return INT_MAX;
    if(i>=l && j <= r)
        return tree[idx];
    int m = (i + j)/2;
    return min(qry(idx*2, i, m, l, r),
                qry(idx*2+1, m+1, j, l, r));
}

ll go(int i, int j){
    if(i >= j) return 1;

    int mn = qry(1, 0, n-1, i, j);
    //printf("mn %d i %d j %d\n", mn, i, j);
    int qtd = upper_bound(pos[mn].begin(), pos[mn].end(), j) -  lower_bound(pos[mn].begin(), pos[mn].end(), i);

    ll ans = cat[qtd];
    int ult = i;
    int ini = lower_bound(pos[mn].begin(), pos[mn].end(), i) - pos[mn].begin();
    for(int a=ini;a < pos[mn].size() && pos[mn][a] <= j;a++){
        // ult ... pos[mn][a]-1
        ans = (ans*go(ult, pos[mn][a]-1))%mod;
        ult = pos[mn][a]+1;
    }
    ans = (ans*go(ult, j))%mod;
    return ans;
}

int main() {
    fastio;

    fat[0] = fat[1] = 1ll;
    frr(i, 2000009) fat[i] = (fat[i-1]*i)%mod;

    // (1/(n+1) * c(2n n))
    cat[0] = cat[1] = 1ll;
    frr(i, 1000002) {
        if (i == 1) continue;
        cat[i] = invmod(i+1);
        cat[i] = (cat[i] * comb(i+i, i))%mod;
    } 

    cin >> n;
    if(n == 0){
        puts("1");
        return 0;
    }

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.pb(x);
        pos[v[i]].push_back(i);
    }

    build(1, 0, n-1);

    ll ans = go(0, n-1);

    p(ans);
}
