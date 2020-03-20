//codeforces.com/contest/1323/problem/A

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

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        int a[n+1];
        frr(i, n) cin >> a[i];
        
        int par = -1, imp = -1;
        frr(i, n) {
            int x = a[i];
            if (x%2)    {
                if (imp == -1) {
                    imp = i;
                    continue;
                }
                p(2);
                cout << imp << " " << i << endl;
                goto fim;
            }
            p(1);
            p(i);
            goto fim;
        }

        p(-1);
        fim:;
    }
}
