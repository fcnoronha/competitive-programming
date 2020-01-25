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
const int N = 1e5 + 2;

pll v[N];

int main(){
    fastio;
    ll M;
    int n; cin >> n >> M;
    fr(i, n){
        ll aa, bb;
        cin >> aa >> bb;
        v[i] = make_pair(aa, bb);
    }

    ll l = 1, r = 1e10;
    ll ans = LINF;
    while(l <= r){
        ll mid = (l+r)/2ll;
        ll plc = 0;
        fr(i, n){
            ll csi = v[i].first*mid - v[i].second;
            plc += max(0ll, csi);
            if(plc >= M) break;
        }
        if(plc >= M){
            r = mid - 1ll;
            ans = min(ans, mid);
        }
        else l = mid + 1ll;
    }
    cout << ans << endl;
}
