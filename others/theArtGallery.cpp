//vjudge.net/contest/367132#problem/A

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

int orientation(pii p1, pii p2, pii p3){
    int val = ((p2.s-p1.s) * (p3.f-p2.f)) - ((p2.f-p1.f) * (p3.s-p2.s));
 	return val;
}

int main() {
    fastio;

    int n;
    while (cin >> n && n) {

        vector<pii> p;
        fr(i, n) {
            int x, y;
            cin >> x >> y;
            p.pb({x,y});
        }

        int c1 = 0, c0 = 0;
        fr(i, n) {
            pii a = p[i];
            pii b = p[(i+1)%n];
            pii c = p[(i+2)%n];

            int aux = orientation(a, b, c);
            if (aux < 0) c1++;
            else c0++;
        }

        if (c1 && c0) p("Yes");
        else p("No");
    }
}
