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

int main(){
    fastio

    int s, w, x, y;

    cin >> w >> s >> x >> y;

    vi wk[w];
    fr(i, w) wk[i].resize(x);

    fr(i, w)
        fr(j, x)
            cin >> wk[i][j];

    vi aux(x, 0);
    vi cut(x, 0); // CENTRAL UNICA DOS TRABALHADORES

    fr(i, s)
        fr(j, x) {
            cin >> aux[j];
            cut[j] = max(cut[j], aux[j]);
        }

    fr(i, w)
        fr(j, x)
        wk[i][j] = min(wk[i][j], max(y-cut[j], 0));

    fr(i, w)
        fr(j, x)
            cout << wk[i][j] << " \n"[j == x-1];
}
