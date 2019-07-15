//codeforces.com/contest/1175/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio

    int l;
    cin >> l;

    ll ans = 0ll;
    bool ov = 0, ovv = 0;
    stack<ll> st;
    st.push(1ll);

    while (l--) {

        string op;
        cin >> op;

        if (op[0] == 'f') {
            ll x;
            cin >> x;

            st.push(st.top() * x);

            if (st.top() > (1ll<<46ll)) {
                st.pop();
                st.push(st.top());
            }

            ovv = (st.top() >= (1ll<<32ll));
        }

        else if (op[0] == 'e') {
            st.pop();
            ovv = (st.top() >= (1ll<<32ll));
        }

        else {
            ans += st.top();

            ov = (ans >= (1ll<<32ll) || ovv);
        }

    }

    if (ov) {
        p("OVERFLOW!!!");
        return 0;
    }

    p(ans);
}
