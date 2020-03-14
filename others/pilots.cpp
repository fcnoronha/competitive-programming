//szkopul.edu.pl/problemset/problem/lcU5m2RAICwNHsdzydb8JTQw/site/?key=statement

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

typedef int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,int> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

struct minq {

    stack< pair<ll, pll> > s1, s2;
    
    int size() {
        return s1.size() + s2.size();
    }

    pll get() {
        if (s1.empty()) return s2.top().s;
        if (s2.empty()) return s1.top().s;
        return make_pair(min(s1.top().s.f, s2.top().s.f), 
                        max(s1.top().s.s, s2.top().s.s));
    }

    void insert(ll val) {
        ll mn, mx;
        mn = mx = val;
        if (!s1.empty()) {
            mn = min(mn, s1.top().s.f);
            mx = max(mx, s1.top().s.s);
        }
        s1.push({val, {mn, mx}});
    }

    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                ll val = s1.top().f;
                s1.pop();
                ll mx = val;
                ll mn = val;
                if (!s2.empty()) {
                    mn = min(mn, s2.top().s.f);
                    mx = max(mx, s2.top().s.s);
                }
                s2.push({val, {mn, mx}});
            }
        }
        s2.pop();
    }
};

int main() {
    fastio;

    ll t, n;
    cin >> t >> n;

    int ans = 1;
    minq q;
    fr(i, n) {
        ll x;
        cin >> x;
        q.insert(x);
        auto aux = q.get();
        while (aux.s-aux.f > t) {
            q.pop();
            aux = q.get();
        }
        ans = max(ans, q.size());
    }

    p(ans);
}
