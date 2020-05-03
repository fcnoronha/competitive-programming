//codeforces.com/contest/1341/problem/C

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
        int pos[n];
        fr(i, n) {
            int x;
            cin >> x;
            pos[x-1] = i;
        }

        int li = -1;
        vi seen(n, 0);
        fr(i, n) {
            if (seen[i]) continue;
            seen[i] = 1;
            int p = pos[i];
            if (li != -1 && p > li) {
                p("No");
                goto fim;
            }
            li = p;
            int j = i+1;
            while (j < n && pos[j] == pos[j-1]+1) {
                seen[j] = 1;
                j++;
            }
        }

        p("Yes");
        fim:;
    }
}
