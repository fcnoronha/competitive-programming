#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

    int m, n;
    cin >> m >> n;
    double r;
    cin >> r;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int dy = abs(ay-by), dx = abs(ax-bx);
    double ans = 10e9;
    fr(nn, n+1) {
        int ddy = abs(ay-nn) + abs(by-nn);
        double aux = (r/(double)n)*double(ddy);

        double mr = (r/(double)n)*double(nn);
        double circ = acos(-1)*mr;
        aux += (circ*double(dx))/double(m);
        ans = min(ans, aux);
    }

    cout << setprecision(8) << fixed << ans << endl;
}
