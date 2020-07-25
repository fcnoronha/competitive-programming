//codeforces.com/contest/1380/problem/A

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
        int a[n];
        fr(i, n) cin >> a[i];

        fr(j, n) {
            int ok1 = -1, ok2 = -1;
            for (int i = j-1; i >= 0; i--) {
                if (a[i] >= a[j]) continue;
                ok1 = i;
                break;
            }
            for (int i = j+1; i < n; i++) {
                if (a[i] >= a[j]) continue;
                ok2 = i;
                break;
            }

            if (ok1 != -1 && ok2 != -1) {
                p("YES");
                cout << ok1+1 << " " << j+1 << " " << ok2+1 << endl;
                goto fim;
            }
        }

        p("NO");
        fim:;
    }
}
