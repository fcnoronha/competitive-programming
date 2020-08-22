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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vi v(n);
        fr(i, n) cin >> v[i];

        if (n == 1) {
            p("Alice");
            continue;
        }

        int i = 0, ii = 0;
        for (; i < n; i++) if (v[i] == 1) ii = i;

        int l = 0, ll = 0;
        for (i = ii-1; i >= 0; i--) {
            if (v[i] < v[i+1]) break;
            l++;
        }
        for (; i >= 0; i--) {
            if (v[i] > v[i+1]) break;
            ll++;
        }
    
        int r = 0, rr = 0;
        for (i = ii+1; i < n; i++) {
            if (v[i] < v[i-1]) break;
            r++;
        }
        for (; i < n; i++) {
            if (v[i] > v[i-1]) break;
            rr++;
        }

        //dbg(r); dbg(rr);

        if (l == 0) {
            if (r == 1) {
                if ((n-1-r-rr)%2 == 0) p("Bob");
                else                   p("Alice");
                goto fim;
            }
            if ((n-1)%2 == 0) p("Alice");
            else              p("Bob");
            goto fim;
        }

        if (r == 0) {
            if (l == 1) {
                if ((n-1-l-ll)%2 == 0) p("Bob");
                else                   p("Alice");
                goto fim;
            }
            if ((n-1)%2 == 0) p("Alice");
            else              p("Bob");
            goto fim;
        }

        if (l == 1 && r == 1) {
            if ((n-l-ll)%2 == 0 || (n-r-rr)%2 == 0) p("Alice");
            else                                    p("Bob");
            goto fim;
        }

        if (n%2) p("Alice");
        else     p("Bob");

        fim:;
    }
}
