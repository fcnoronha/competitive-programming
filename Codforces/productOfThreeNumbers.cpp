//codeforces.com/contest/1294/problem/C

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

set<int> findd(int n) {
    set<int> divs;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            divs.insert(i);
            if (n%(n/i) == 0 && (n/i) >= 2) divs.insert(n/i);
        }
    }
    return divs;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        auto divs = findd(n);
        for (auto d: divs) {
            auto aux = findd(d);
            for (auto dd: aux) {
                set<int> ans;
                if (n/d < 2) continue;
                ans.insert(n/d);
                ans.insert(dd);
                if ((d/dd) < 2) continue; 
                ans.insert((d/dd));
                if (ans.size() != 3) continue;
                p("YES");
                for (auto x: ans) cout << x << " ";
                cout << endl;
                goto fim;
            }
        }

        p("NO");
        fim:;
    }
}
