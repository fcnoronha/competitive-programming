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
const ll MOD = 1000000007;

typedef complex<double> base;
const double PI = acos(-1);

void fft(vector<base> &a, bool invert) {
    ll n = (ll)a.size();
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n>>1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (ll i = 0; i < n; i += len) {
            base w(1);
            for (ll j = 0; j < len/2; j++) {
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j]       = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }

    if (invert) for(ll i = 0; i < n; i++) a[i] /= n;
}

// a, b => coefs to multiply,  res => resulting coefs
// a[0], b[0], res[0] = coef x^0
// Doesnt work with negative coefs
vector<ll> multiply(const vector<ll> &a, const vector<ll> &b) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    size_t n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);
    
    fft(fa, false); fft(fb, false);
    for (size_t i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> res(n);
    // avoid precision errors, mess up with negative values of coefs
    for(size_t i = 0; i < n; i++)
        res[i] = ll(fa[i].real() + 0.5);
    
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    string s; cin >> s;
    int n = s.size();

    vl ans(n+n, 0);
    for (auto c: {'a', 'b', 'c'}) {

        vl a, b;
        for (auto cc: s) {
            a.pb(cc==c);
            b.pb(cc==c);
        }

        reverse(all(b));
        vl f = multiply(a, b);
        fr(i, n+n) ans[i] += f[i];
    }

    ll bst = 0;
    fr(i, n-1) bst = max(bst, ans[i]);

    p(bst);
    frr(i, n) if (ans[n-i] == bst) cout << i-1 << " ";
    cout << endl;
}
