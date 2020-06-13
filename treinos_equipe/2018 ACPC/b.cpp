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

const ld eps = 0.00000000000001;

int main() {
    fastio;
    cout << setprecision(6) << fixed;
    #ifdef ONLINE_JUDGE
    freopen("baklava.in", "r", stdin);
    #endif

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        ld theta = (acos(-1)/180.0) * 360.0/(2.0*n);
        ld ans = 1.0;
        ld old_area = 1.0;
        ld l = sqrt(tan(theta)/ld(n));
        ld h = l/tan(theta);
        
        ld iter = 0.0;
        while (++iter) {
            
            ld new_l = sin(theta)*h;
            ld new_h = new_l/tan(theta);
            ld new_area = ld(n) * new_h * new_l;
            
            ld dif = -(iter*old_area) + iter*(old_area-new_area) + (iter+1.0)*(new_area);
            if (abs(dif) < eps) break;
            ans += dif;
            l = new_l;
            h = new_h;
            old_area = new_area;
        }

        p(10000.0 * ans);
    }
}
