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
const int N = 360000;

const int mod = 360000;
int n;

bool cmp(vi a, vi b) {

    fr(i, n-1) 
        if (a[i] != b[i])
            return false;
    return true;
}

int main(){
    fastio;

    cin >> n;

    vi a(n), b(n);
    fr(i, n) cin >> a[i];
    fr(i, n) cin >> b[i];

    sort(all(a));
    sort(all(b));

    vi d1, d2, d3, d4;
    fr(i, n-1) {

        d1.pb((a[i+1]-a[i])%mod);
        d3.pb((b[i+1]-b[i])%mod);
    }

    for (auto &x: a) 
        x = (mod+mod-x)%mod;
    sort(all(a));
    fr(i, n-1)
        d2.pb((a[i+1]-a[i])%mod);

    if (cmp(d1, d3) || cmp(d2, d3)) {
            p("possible");
            return 0;
        }
    
    p("impossible");
}
