//codeforces.com/contest/1287/problem/C

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

int memo[101][2][60][60], a[101], avlb[101];
int n, fpar, fimp, ft;

int pd(int i, int ant, int free_par, int free_impar) {

    if (i == n) return 0;

    int &pdm = memo[i][ant][free_par][free_impar];
    if (pdm != -1) return pdm;

    if (a[i] != 0) {
        int act = a[i]%2;
        pdm = pd(i+1, act, free_par, free_impar) + (act != ant);
        return pdm;
    }

    //dbg(i), dbg(free_impar), dbg(free_par);

    pdm = INF;
    if (free_par) pdm = min(pdm, pd(i+1, 0, free_par-1, free_impar)+(0!=ant));
    if (free_impar) pdm = min(pdm, pd(i+1, 1, free_par, free_impar-1)+(1!=ant));
    return pdm;
}

int main(){
    fastio;

    cin >> n;

    fr(i, n) cin >> a[i], avlb[a[i]] = 1;

    frr(i, n) {
        if (avlb[i]) continue;
        fpar += (i%2 == 0);
        fimp += (i%2);
    }

    ms(memo, -1);
    int ans = min(pd(0, 1, fpar, fimp), pd(0, 0, fpar, fimp));
    p(ans);
}
