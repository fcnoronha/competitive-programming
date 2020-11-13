//codeforces.com/contest/1435/problem/C

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

#define maxn 112345

ll b[maxn];
ll a[6];
ll n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    fr(i, 6) cin >> a[i];
    cin >> n;
    fr(i, n) cin >> b[i];

    vector<pll> aux;
    fr(i, n) fr(j, 6) aux.pb({b[i]-a[j], i});
    sort(all(aux));

    ll ans = LINF, cnt = 0;
    map<ll, ll> mp;
    int l = 0, r = 0, nn = n*6; 
    for (; l < nn && r < nn; l++) {

        //if (aux[l].f == 100) dbgpt(aux[r]), dbg(cnt);
        if (cnt == n) ans = min(ans, aux[r-1].f-aux[l].f);
        while (r < nn && cnt < n) {
            if (mp[aux[r].s]++ == 0) cnt++;
            r++;
        }
        if (cnt == n) ans = min(ans, aux[r-1].f-aux[l].f);

        if (--mp[aux[l].s] == 0) cnt--;
    }

    p(ans);
}
