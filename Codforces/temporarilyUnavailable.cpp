//codeforces.com/contest/1282/problem/A

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

    int t;
    cin >> t;

    while (t--) {

        int a, b, c, r;
        cin >> a >> b >> c >> r;

        if (b < a) swap(a, b); 

        // a --- c ---- b
        if (a <= c && c <= b) {

            int l1 = c-a;
            l1 = max(0, l1-r);
            int l2 = b-c;
            l2 = max(0, l2-r);

            p(l1+l2);
            continue;
        }
        // c --- a ----- b
        if (c < a) {
            
            int l1 = b;
            if (c+r <= a) l1 -= a;
            else l1 -= c+r;

            l1 = max(l1, 0);
            p(l1);
            continue;
        }

        int l1 = min(c-r, b);
        l1 -= a;
        l1 = max(l1, 0);
        p(l1);
    }
}