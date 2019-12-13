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

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n; 

        int v[n], pos[n+1];
        fr(i, n) cin >> v[i], pos[v[i]] = i;

        int ac[n+1];
        ac[0] = 0;
        frr(i, n) 
            ac[i] = ac[i-1] + v[i-1];

        int ans[n+1];
        ms(ans, 0);
        int l, r;

        l = r = pos[1];
        fr(i, n) {
            
            l = min(l, pos[i+1]);
            r = max(r, pos[i+1]);
            if (r - l == i) ans[i] = 1;
        }

        fr(i, n) cout << ans[i];
        cout << endl;
    }
}
