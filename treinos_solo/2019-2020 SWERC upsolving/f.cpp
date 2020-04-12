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

double area(vector<pair<double, double>> p) {
    int n = p.size();
    double ans = 0.0;
    for (int i = 0; i < n; i++) 
        ans += (p[(i+1)%n].f + p[i].f) * (p[(i+1)%n].s - p[i].s);
    return abs(ans/2.0);
}

int main() {
    fastio;

    int n;
    cin >> n;

    ll ans = 0ll;
    fr(k, n) {
        ll aux = 0ll;
        int p;
        cin >> p;
        pll pl[p];
        fr(i, p) cin >> pl[i].f >> pl[i].s;
        fr(i, p) {
            int j = (i+1)%p;
            aux += (pl[j].f + pl[i].f) * (pl[j].s - pl[i].s);
        }
        ans += abs(aux);
    }

    p((ans)/2);
}
