//codeforces.com/contest/1272/problem/D

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

    int n;
    cin >> n;

    int a[n];
    fr(i, n) cin >> a[i];

    int ok = 1;
    frr(i, n-1) if (a[i] <= a[i-1]) ok = 0;

    if (ok) {
        p(n);
        return 0;
    }

    vector< pair<vi, int> > v; // {{mn1, mn2, mx1, mx2}, length}

    int l = 0;
    frr(i, n) {

        if (i == n || a[i] <= a[i-1]) {

            int lg = 0;
            vi aux;
            for (int j = l; j < i; j++) 
                lg++;

            if (lg <= 4) {
                for (int j = l; j < i; j++)
                    aux.pb(a[j]);
            }
            else {
                for (int j = l; j < l+2; j++)
                    aux.pb(a[j]);
                for (int j = i-2; j < i; j++)
                    aux.pb(a[j]);
            }

            v.pb({aux, lg});
            l = i;
        }
    }

    // for (auto x: v) dbg(x.f.f), dbg(x.f.s), dbg(x.s);

    int ans = 1;
    fr(i, v.size()-1) {

        auto x1 = v[i];
        auto x2 = v[i+1];

        ans = max({ans, x1.s, x2.s});
        
        vi v1 = x1.f; int n1 = v1.size();
        vi v2 = x2.f; int n2 = v2.size();

        if (v1[n1-1] < v2[0]) {
            ans = max(ans, x1.s+x2.s);
            continue;
        }

        if (n1 > 1 && v1[n1-2] < v2[0]) {
            ans = max(ans, x1.s+x2.s-1);
            continue;
        }

        if (n2 > 1 && v1[n1-1] < v2[1]) {
            ans = max(ans, x1.s+x2.s-1);
            continue;
        }
    }

    p(ans);
}
