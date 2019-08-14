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

int main(){
    fastio

    int t;
    cin >> t;

    cout << fixed << setprecision(5);

    while (t--) {

        int n;
        cin >> n;

        vector<double> v(n);
        for (auto &x : v) cin >> x;

        sort(all(v));

        double ans = DBL_MAX;

        fr(i, n)
            fr(j, n) {
                if (i == j) continue;

                double a = v[i];
                double b = v[j];

                auto it = upper_bound(all(v), abs(a-b));
                int idx = it - v.begin();
                while (idx == i || idx == j) idx++;

                if (idx >= n) continue;
                double c = v[idx];
                if (c > a+b) continue;

                double sp = (a+b+c)/2.0;
                double aux = sqrt(sp*(sp-a)*(sp-b)*(sp-c));

                ans = min(ans, aux);
            }

        if (ans < DBL_MAX) p(ans);
        else p("-1");
    }
}
