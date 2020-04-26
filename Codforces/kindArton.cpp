//codeforces.com/contest/1333/problem/C

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
        int a[n], b[n];
        fr(i, n) cin >> a[i];
        fr(i, n) cin >> b[i];

        int deu = (a[0]==b[0]), m1 = (a[0] < 0), p1 = (a[0]>0);
        frr(i, n-1) {

            int d = a[i]-b[i];
            if (d > 0 && m1 <= 0) deu = 0;
            if (d < 0 && p1 <= 0) deu = 0; 

            if (a[i] > 0) p1++;
            if (a[i] < 0) m1++;
        }

        if (deu) p("YES");
        else p("NO");
    }
}
