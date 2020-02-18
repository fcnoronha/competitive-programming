//codeforces.com/contest/148/problem/D

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

#define pri 0
#define dg 1

ld memo[2][1009][1009];
bool seen[2][1009][1009];

ld pd(int p, int W, int B) {

    if (W <= 0 || B < 0) return 0.0;

    ld &pdm = memo[p][W][B];
    if (seen[p][W][B]) return pdm;
    seen[p][W][B] = 1;

    ld w = W;
    ld b = B;
    pdm = 0.0;
    if (p == pri) {
        pdm = w/(w+b);
        pdm += (b/(b+w))*pd(dg, W, B-1);
        return pdm;
    }
    if (B+W > 1 && B > 0) {
        pdm = b/(w+b);
        pdm *= ((w/(w+b-1.0)*pd(pri, W-1, B-1)) + ((b-1.0)/(w+b-1.0))*pd(pri, W, B-2));
        return pdm;
    }
    return pdm;
}

int main(){
    fastio;

    int w, b;
    cin >> w >> b;

    cout << fixed << setprecision(9);
    p(pd(pri, w, b));
}
