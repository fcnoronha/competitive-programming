//codeforces.com/contest/1380/problem/D 

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
    fastio;

    ll n, m;
    cin >> n >> m;
    n++, m++;

    ll x, k, y;
    cin >> x >> k >> y;

    ll a[n], b[m];
    fr(i, n-1) cin >> a[i];
    fr(i, m-1) cin >> b[i];

    a[n-1] = 0;
    b[m-1] = 0;

    if (m > n) {
        p(-1);
        return 0;
    }

    ll ans = 0ll, ib = 0, l = -1, j = 0, i = 0;
    while (i < n) {
        while (i < n && a[i] != b[ib]) i++;
        if (i == n) break;

        ll fl = -LINF, fr = a[i];
        if (l != -1) fl = a[l];
        //////////////////////////////////////
        
        ll amt = i, aux = LINF, mx = -1;
        if (l != -1) amt = i-l-1;
        if (amt == 0) goto fim;

        for (j = l+1; j < i; j++) mx = max(mx, a[j]);
        if (amt%k == 0) aux = (amt/k)*x;
        if ((l != -1 && a[l] > mx) || a[i] > mx) aux = min(aux, y*amt);
        if (amt > k) {
            aux = min(aux, (amt/k)*x + (amt%k)*y);
            aux = min(aux, x + (amt-k)*y);
        }
        if (aux == LINF) break;
        ans += aux;

        //////////////////////////////////////
        fim:;
        l = i; 
        i++, ib++;
    }
    
    if (i == n && ib == m) {
        p(ans);
        return 0;
    }
    p(-1);
}
