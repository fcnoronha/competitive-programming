//codeforces.com/contest/1257/problem/E

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

int main(){
    fastio;

    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;

    int n = k1+k2+k3;
    int aux;
    vi a(n+1, 0);
    fr(i, k1) {
        cin >> aux;
        a[aux] = 0;
    }
    fr(i, k2) {
        cin >> aux;
        a[aux] = 1;
    }
    fr(i, k3) {
        cin >> aux;
        a[aux] = 2;
    }

    int ans = 0, best = 0;
    vi cntr(3, 0);
    vi cntl(3, 0);

    frr(i, n) if (a[i] != 2) ans++;

    frr(i, n) cntr[a[i]]++;

    frr(i, n) {

        cntl[a[i]]++;
        cntr[a[i]]--;

        best = max(best, cntl[0]-cntl[1]);
        int aux = cntr[0] + cntr[1] + cntl[2] + cntl[0] - best;
        ans = min(aux, ans);
    }

    p(ans);
}
