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

int solve(vector<int> &v, int t) {

    int ans = 0;
    auto it = lower_bound(v.begin(),v.end(),0);
    for(auto pos = it;pos!=v.end();pos++) {
        if(*pos<=t) ans++;
    }
    for(auto i=v.begin();i!=v.end();i++) {
        if(*i>=0)   continue;
        int cost = 2 *abs(*i);
        if(cost>t)  continue;
        int rem_cost = t - cost;
        auto nxt = upper_bound(v.begin(),v.end(),rem_cost);
        int frente = nxt - v.begin();
        int from = i-v.begin();
        ans=max(ans,frente-from);
    }

    return ans;

}

int main() {
    fastio;

    int n, t ;
    cin >> n >> t;
    vector<int> v(n);
    fr(i,n) cin>>v[i];
    int ans = solve(v,t);
    fr(i,n) v[i]=-1*v[i];
    reverse(v.begin(),v.end());
    ans=max(ans,solve(v,t));
    cout << ans << endl;


}







