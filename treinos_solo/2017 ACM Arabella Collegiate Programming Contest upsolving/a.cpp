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
    fastio;

    int t;
    cin >> t;

    while (t--) {

        ll n;
        cin >> n;
        string s;
        cin >> s;

        vl aux;
        ll cnt = 0;
        fr(i, n) {
            cnt++;
            if (s[i] == '1') {
                aux.pb(cnt);
                cnt = 0;
            }
        }
        aux.pb(cnt+1);
        ll nn = aux.size();
        ll l1 = 0ll, l2 = 0ll;
        for (int i = 0; i < nn; i += 2) l1 += aux[i];
        for (int i = 1; i < nn; i += 2) l2 += aux[i];
        ll ans = l1*l2;
        fr(i, nn) ans -= 2*aux[i];
        ans += aux[0]+aux[nn-1]+nn-1;

        p(ans);
    }
}
