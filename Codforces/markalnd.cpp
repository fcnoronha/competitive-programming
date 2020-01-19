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

        int n, s, k;
        cin >> n >> s >> k;

        map<int, int> closed;
        int aux;
        fr(i, k) {
            cin >> aux;
            closed[aux] = 1;
        }

        if (closed[s] == 0) {
            p("0");
            continue;
        }

        int ans = INF;
        for (int i = s; i <= n; i++) {
            if (closed[i] == 0) {
                ans = min(ans, i-s);
                break;
            }
        }

        for (int i = s; i >= 1; i--) {
            if (closed[i] == 0) {
                ans = min(ans, s-i);
                break;
            }
        }

        p(ans);
    }
}
