//codeforces.com/contest/1363/problem/A

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

        int n, x;
        cin >> n >> x;
        int cntp = 0, cnti = 0;
        fr(i, n) {
            int aux;
            cin >> aux;
            cntp += (aux%2 == 0);
            cnti += (aux%2 == 1);
        }

        int aux = min(cnti-(cnti%2==0), x-(x%2==0));
        if (aux > 0 && aux + cntp >= x) {
            p("Yes");
        }
        else {
            p("No");
        }
    }
}
