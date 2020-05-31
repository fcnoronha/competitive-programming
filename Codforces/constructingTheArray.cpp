//codeforces.com/contest/1353/problem/D

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

        int n;
        cin >> n;
        vi ans(n);
        set< pair<int, pii> > st;
        int it = 1;
        st.insert({-n, {0, n-1}});
        while (!st.empty()) {
            auto aux = *st.begin();
            st.erase(aux);

            int l = aux.s.f, r = aux.s.s;
            int m = (r+l)/2;
            ans[m] = it++;
            if (r > l) {
                if (m-1 >= l) st.insert({-(m-l+1), {l, m-1}});
                if (m+1 <= r) st.insert({-(r-m+1), {m+1, r}});
            }
        }

        pv(ans);
    }
}
