//codeforces.com/gym/100883/problem/A

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ld a[21][21];
ld memo[(1<<21)];

int main(){
    fastio

    int t;
    cin >> t;

    frr(to, t) {

        int n;
        cin >> n;

        fr(i, n)
            fr(j, n)
                cin >> a[i][j];

        ms(memo, 0.0);
        memo[(1<<n)-1] = 1.0;

        for (int i = (1<<n)-1; i >= 0; i--) {

            if (!memo[i]) continue;

            int cnt = 0;
            vi peop;

            fr(j, n)
                if (i & (1<<j))
                    peop.pb(j), cnt++;

            for (auto p1 : peop)
                for (auto p2 : peop)
                    if (p1 != p2)
                        memo[i - (1<<p2)] += a[p1][p2]*memo[i]/(cnt*(cnt-1)/2);

        }

        cout << "Case " << to << ":";
        fr(i, n)
            cout << setprecision(6) << fixed << " " << memo[1<<i];
        cout << "\n";
    }
}
