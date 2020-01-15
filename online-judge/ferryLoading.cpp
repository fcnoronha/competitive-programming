//uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1202

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

vi cars, acum;
int sz, aux, memo[209][20009], ans[209][20009];

int pd(int i, int v) {

    if (i == cars.size()) return 0;
    if (v+cars[i] > sz && acum[i]-v > sz) return 0;
    if (memo[i][v] != -1) return memo[i][v];

    int a = 0, b = 0;
    if (v+cars[i] <= sz)
        a = pd(i+1, v+cars[i]) + 1;

    if (acum[i]-v <= sz)
        b = pd(i+1, v) + 1;

    if (a > b) {
        ans[i][v] = 2;
        memo[i][v] = a;
    }
    else {
        ans[i][v] = 1;
        memo[i][v] = b;
    }

    return memo[i][v];
}

int main(){
    fastio;

    int t; cin >> t;
    int to = t;
    while (t--) {

        if (t < to-1) cout << endl;

        cars.clear();
        acum.clear();
        ms(memo, -1);
        ms(ans, 0);

        cin >> sz; sz *= 100;

        while (cin >> aux && aux) {
            cars.pb(aux);
            if (acum.size()) acum.pb(acum.back()+aux);
            else acum.pb(aux);
        }

        if (cars.empty()) {
            cout << "0\n";
            continue;
        }

        int oi = pd(0, 0), v = 0;
        cout << oi << endl;
        fr(i, oi) {
            if (ans[i][v] == 1) {
                cout << "starboard\n";
            }
            else {
                cout << "port\n";
                v += cars[i];
            }
        }
    }
}
