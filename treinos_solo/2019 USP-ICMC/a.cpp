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

int main() {

    int n;
    cin >> n;

    pii bld[n];
    fr(i, n) {
        cin >> bld[i].f;
        bld[i].s = i+1;
    }
    sort(bld, bld+n);
    reverse(bld, bld+n);

    int ans[n];
    set<int> s;
    int act_h = bld[0].f;

    fr(i, n) {

        int h = bld[i].f, pos = bld[i].s;
        if (act_h != h) {

            for (int j = i-1; j >= 0; j--) {
                if (bld[j].f != act_h) break;
                s.insert(bld[j].s);
            }                   
            act_h = h;
        }

        auto x = s.upper_bound(pos);
        int aux;

        if (x == s.end()) aux = INF; 
        else aux = (*x)-1;
        
        aux = min({n, h+pos, aux});
        ans[pos-1] = aux-pos;
    }
    
    fr(i, n) cout << ans[i] << " ";
    cout << endl;
}