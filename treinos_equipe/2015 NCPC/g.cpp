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

    int g;
    cin >> g;

    vector<pii> vg;
    fr(i, g) {
        int x, y;
        cin >> x >> y;
        vg.pb({x,y});
    }

    int m;
    cin >> m;

    vector<pii> vm;
    vi r;
    fr(i, m) {
        int x, y, aux;
        cin >> x >> y >> aux;
        vm.pb({x,y});
        r.pb(aux);
    }

    int ans = g;
    fr(i, g) {

        fr (j, m) {

            ll aux = (vg[i].f-vm[j].f)*(vg[i].f-vm[j].f) + (vg[i].s-vm[j].s)*(vg[i].s-vm[j].s);
            if (aux <= r[j]*r[j]) {
                ans--;
                break;
            }
        
        }

    }

    cout << ans << endl;
}
