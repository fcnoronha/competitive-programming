//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1251

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

ll read_double() {

    double aux;
    cin >> aux;

    aux *= 1000.0;
    return ll(aux);
}

int main(){
    fastio

    int n;
    while (cin >> n) {

        ll gx, gy, dx, dy;
        gx = read_double();
        gy = read_double();
        dx = read_double();
        dy = read_double();

        ll x, y, ansx, ansy;
        bool achei_res = 0;
        fr(i, n) {

            x = read_double();
            y = read_double();

            if (achei_res) continue;

            ll d1 = (gx-x)*(gx-x) + (gy-y)*(gy-y);
            ll d2 = (dx-x)*(dx-x) + (dy-y)*(dy-y);
            //dbg(x), dbg(y);

            if (d1*4ll <= d2) {
                ansx = x;
                ansy = y;
                achei_res = 1;
            }
        }

        if (!achei_res) {
            printf("The gopher cannot escape.\n");
            continue;
        }

        double oi = ansx/1000.0;
        double ola = ansy/1000.0;
        printf("The gopher can escape through the hole at (%.3f,%.3f).\n", oi, ola);
    }
}
