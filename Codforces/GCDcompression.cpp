//codeforces.com/contest/1370/problem/B

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

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        set<int> odd, eve;
        fr(i, n+n) {
            int x;
            cin >> x;
            if (x%2) odd.insert(i+1);
            else     eve.insert(i+1);
        }

        if ((int)odd.size()%2) {
            odd.erase(odd.begin());
            eve.erase(eve.begin());
        }
        else {
            if (odd.size()) {
                odd.erase(odd.begin());
                odd.erase(odd.begin());
            }            
            else {
                eve.erase(eve.begin());
                eve.erase(eve.begin());
            }
        }

        while (!eve.empty()) {
            int a = *eve.begin();
            eve.erase(a);
            int b = *eve.begin();
            eve.erase(b);
            cout << a << " " << b << endl;
        }               

        while (!odd.empty()) {
            int a = *odd.begin();
            odd.erase(a);
            int b = *odd.begin();
            odd.erase(b);
            cout << a << " " << b << endl;
        }
    }
}
