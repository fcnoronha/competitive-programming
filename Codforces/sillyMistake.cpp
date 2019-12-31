//codeforces.com/contest/1253/problem/B

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

    int n;
    cin >> n;

    vi ans;
    set<int> s;
    int nda = 0;
    int lst = -1;
    bool vis[1000009];
    ms(vis, 0);
    vi changed;

    int a;
    fr(i, n) {

        cin >> a;
        if (nda) continue;

        if (a > 0) {
            
            if (s.find(a) != s.end()) {
                nda = 1;
                continue;
            } 

            if (vis[a]) {
                nda = 1;
                continue;
            }

            vis[a] = 1;
            changed.pb(a);
            s.insert(a);
            continue;
        } 
        
        a = -a;
        if (s.find(a) == s.end()) {
            nda = 1;
            continue;
        } 
        s.erase(a);

        if (s.size() == 0) {
            ans.pb(i-lst);
            lst = i;
            
            for (auto x: changed) vis[x] = 0;
            changed.clear();
        }
    }

    if (s.size()) nda = 1;

    if (nda) {
        p("-1");
        return 0;
    }

    cout << ans.size() << endl;
    pv(ans);
}
