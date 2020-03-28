//codeforces.com/contest/1313/problem/C2

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

vl ns(vl &m) {

    ll n = m.size();
    vl near;
    stack< pll > st; 
    fr(i, n) {
        while (!st.empty() && st.top().first >= m[i]) 
            st.pop(); 

        if (st.empty()) near.push_back(-1);
        else near.push_back(st.top().second);

        st.push({m[i], i}); 
    }
    return near;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    vl m(n), l(n), r(n);
    fr(i, n) cin >> m[i];

    vl near = ns(m);
    fr(i, n) {
        int j = near[i];
        if (j == -1) {
            l[i] = m[i]*(i+1);
            continue;
        }
        l[i] = l[j] + (i-j)*m[i];
    }

    reverse(all(m));
    near = ns(m);
    reverse(all(m));
    reverse(all(near));
    for (auto &x: near) {
        if (x == -1) continue;
        x = n-x-1;
    }
    for (int i = n-1; i >= 0; i--) {
        ll j = near[i];
        if (j == -1) {
            r[i] = m[i]*(n-i);
            continue;
        }
        r[i] = r[j] + (j-i)*m[i];
    }

    ll ans = 0, idx_ans = 0;
    fr(i, n) {
        ll aux = l[i]+r[i]-m[i];
        if (aux > ans) {
            ans = aux;
            idx_ans = i;
        }
    }

    ll mn = m[idx_ans];
    for (int i = idx_ans+1; i < n; i++) {
        m[i] = min(m[i], mn);
        mn = min(mn, m[i]);
    }
    mn = m[idx_ans];
    for (int i = idx_ans-1; i >= 0; i--) {
        m[i] = min(m[i], mn);
        mn = min(mn, m[i]);
    }

    fr(i, n) cout << m[i] << " \n"[i==n-1];
}
