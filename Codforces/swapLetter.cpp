//codeforces.com/contest/1215/problem/C

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vi a, b;
    fr(i, n) {
        if (s[i] == t[i]) continue;
        if (s[i] == 'a') a.pb(i);
        else b.pb(i);
    }

    if (a.size()%2 != b.size()%2) {
        p("-1");
        return 0;
    }


    vector<pii> ans;
    for (int i = 0; i < (int)a.size()-1; i+=2)
        ans.pb({a[i], a[i+1]});

    for (int i = 0; i < (int)b.size()-1; i+=2)
        ans.pb({b[i], b[i+1]});

    if (a.size()%2) {
        int x = a[a.size()-1];
        int y = b[b.size()-1];
        ans.pb({x,x});
        ans.pb({x,y});
    }

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x.f+1 << " " << x.s+1 << "\n";
}
