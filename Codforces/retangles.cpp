//codeforces.com/contest/1028/problem/C

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

typedef pair<pii, pii> quad;
#define x0 f.f
#define y0 f.s
#define x1 s.f
#define y1 s.s

pii pega_cima(pii a, pii b) {

    pii ret;
    ret.f = max(a.f, b.f);
    ret.s = max(a.s, b.s);
    return ret;
}

pii pega_baixo(pii a, pii b) {

    pii ret;
    ret.f = min(a.f, b.f);
    ret.s = min(a.s, b.s);
    return ret;
}

bool check(quad q) {
    if (q.x0 > q.x1 || q.y0 > q.y1) return false;
    return true;
}

int main(){
    fastio;

    pii trouxa = {INT_MIN, INT_MIN};

    int n;
    cin >> n;

    quad q[n];
    fr(i, n) {
        cin >> q[i].x0 >> q[i].y0;
        cin >> q[i].x1 >> q[i].y1;
    }

    quad pre[n], suf[n];
    pre[0] = q[0];
    suf[n-1] = q[n-1];

    frr(i, n-1) {
        pre[i].f = pega_cima(q[i].f, pre[i-1].f);
        pre[i].s = pega_baixo(q[i].s, pre[i-1].s);
    }

    for (int i = n-2; i >= 0; i--) {
        suf[i].f = pega_cima(q[i].f, suf[i+1].f);
        suf[i].s = pega_baixo(q[i].s, suf[i+1].s);
    }

    if (check(pre[n-1])) {
        cout << pre[n-1].f.f << " " << pre[n-1].f.s << endl;
        return 0;
    }
    if (n >= 2 && check(pre[n-2])) {
        cout << pre[n-2].f.f << " " << pre[n-2].f.s << endl;
        return 0;
    }
    if (n > 1 && check(suf[1])) {
        cout << suf[1].f.f << " " << suf[1].f.s << endl;
        return 0;
    }

    for (int i = 1; i < n-1; i++) {

        quad q1 = pre[i-1];
        quad q2 = suf[i+1];
        quad ans = {pega_cima(q1.f, q2.f), pega_baixo(q1.s, q2.s)};

        if (check(ans)) {
            cout << ans.f.f << " " << ans.f.s << endl;
            return 0;
        }
    }
}
