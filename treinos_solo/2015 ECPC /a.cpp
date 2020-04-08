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
    cout << setprecision(9) << fixed;
    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;
        string n = s;
        sort(all(n));

        int n_perm = 0;
        do {
            n_perm++;
        } while(next_permutation(all(n)));

        reverse(all(n));
        double ans = 0.0, ac_prob = 0.0;
        while (n != s) {

            double cur_ans = 1.0/double(n_perm) + ac_prob;
            ans = cur_ans;
            ac_prob += cur_ans/double(n_perm);

            prev_permutation(all(n));
        } 

        cout << ans << endl;
    }
}
