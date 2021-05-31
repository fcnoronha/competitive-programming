#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;

        map<int, int> f;
        fr(i, n) {
            int x; cin >> x;
            f[x]++;
        }

        multiset<int> st;
        for (auto x: f) st.insert(-x.s);
        while (st.size() > 1) {
            int a = *st.begin(); st.erase(st.find(a));
            int b = *st.begin(); st.erase(st.find(b));
            a++, b++;
            if (a) st.insert(a);
            if (b) st.insert(b);
        }

        int ans = 0;
        if (!st.empty()) ans = -*st.begin();
        p(ans);
    }
}
