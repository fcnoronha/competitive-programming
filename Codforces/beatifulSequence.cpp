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

    vi num(4);
    for (auto &x : num) cin >> x;

    int n = 0;
    for (auto x : num) n += x;

    fr (ini, 4) {
        
        if (num[ini] == 0) continue;
        
        vi ans, aux;
        for (auto x : num) aux.pb(x);

        ans.pb(ini);
        int last = ini;
        aux[ini]--;

        fr(i, n-1) {

            if (last-1 >= 0 && aux[last-1]) {
                last--;
                aux[last]--;
                ans.pb(last);
            }
            else if (last+1 < 4 && aux[last+1]) {
                last++;
                aux[last]--;
                ans.pb(last);
            }
            else goto FIM;
        }

        p("YES");
        pv(ans);
        return 0;

        FIM: continue;
    }

    p("NO");
}
