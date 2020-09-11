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

int lis(vector<pll> &v){
	vector<ll> st; 
	for (auto x: v) {
		auto it = upper_bound(st.begin(), st.end(), x.s);
		if (it == st.end()) st.pb(x.s);
		else *it = x.s;
	}
	return st.size();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n;
    cin >> n;

    pll s, t;
    cin >> s.f >> s.s;
    cin >> t.f >> t.s;

    if (s.f > t.f) swap(s,t); // s is before t in x-axys

    vector<pll> v;
    while (n--) {
        ll x, y;
        cin >> x >> y;
        if (x < s.f || x > t.f) continue;
        if (y < min(s.s, t.s) || y > max(s.s, t.s)) continue;
        v.pb({x,y});
    } 

    if (s.s > t.s) for (auto &x: v) x.s = -x.s;

    sort(all(v));
    p(lis(v));
}
