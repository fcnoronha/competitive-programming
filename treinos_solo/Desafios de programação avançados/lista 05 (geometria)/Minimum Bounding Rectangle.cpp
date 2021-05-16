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

void gmx(pii &a, pii b) {
    a.f = max(a.f, b.f);
    a.s = max(a.s, b.s);
}

void gmn(pii &a, pii b) {
    a.f = min(a.f, b.f);
    a.s = min(a.s, b.s);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;
    while (t--) {

        pii mx = {-INF, -INF}, mn = {INF, INF};

        int n; cin >> n;
        while (n--) {

            char op; cin >> op;
            pii a;

            if (op == 'p') {
                cin >> a.f >> a.s;
                gmx(mx, a);
                gmn(mn, a);
            }

            if (op == 'c') {
                cin >> a.f >> a.s;

                int r; cin >> r;

                for (auto d: vector<pii>({{0,1}, {0,-1}, {1,0}, {-1,0}})) {
                        
                    pii b = {a.f + d.f*r, a.s + d.s*r};
                    gmx(mx, b);
                    gmn(mn, b);
                }
            }

            if (op == 'l') {
                cin >> a.f >> a.s;
                gmx(mx, a);
                gmn(mn, a);
                
                cin >> a.f >> a.s;
                gmx(mx, a);
                gmn(mn, a);
            }

        }

        cout << mn.f << " " << mn.s << " " << mx.f << " " << mx.s << endl;
    }
}
