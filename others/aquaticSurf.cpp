//www.urionlinejudge.com.br/judge/en/problems/view/2560

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

struct mmq {
    stack< pair<ll, pll> > s1, s2;

    pll get() {
        if (s1.empty()) return s2.top().s;
        if (s2.empty()) return s1.top().s;
        ll mn = min(s2.top().s.f, s1.top().s.f);
        ll mx = max(s2.top().s.s, s1.top().s.s);
        return {mn, mx};
    }

    void insert(ll val) {
        ll mn = val;
        ll mx = val;
        if (!s1.empty()) mn = min(mn, s1.top().s.f);
        if (!s1.empty()) mx = max(mx, s1.top().s.s);
        s1.push({val, {mn, mx}});
    } 

    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                ll val = s1.top().f;
                s1.pop();
                ll mn = val;
                ll mx = val;
                if (!s2.empty()) mn = min(mn, s2.top().s.f);
                if (!s2.empty()) mx = max(mx, s2.top().s.s);
                s2.push({val, {mn, mx}});
            }
        }
        s2.pop();
    }
};

int main(){
    fastio;

    ll n, b;
    while (cin >> n >> b) {

        ll a[n+2], sm = 0ll, ans = 0ll;
        fr(i, n) cin >> a[i];

        mmq q;

        fr(i, b) {
            sm += a[i];
            q.insert(a[i]);
        }

        int l = b, r = 0;
        while (l <= n) {

            ans += sm;
            pll aux = q.get();
            ans -= (aux.f + aux.s);

            sm += a[l];
            q.insert(a[l]);
            sm -= a[r];
            q.pop();

            l++; r++;
        }

        p(ans);
    }
}
