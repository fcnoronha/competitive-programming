//codeforces.com/contest/1499/problem/A

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

        int n, k1, k2;
        cin >> n >> k1 >> k2;

        int w, b;
        cin >> w >> b;

        bool f1 = 0, f2 = 0;

        int aux;

        aux = min(k1, k2);
        if (aux + (k1-aux)/2 + (k2-aux)/2 >= w) f1 = 1;

        k1 = n-k1;
        k2 = n-k2;

        aux = min(k1, k2);
        if (aux + (k1-aux)/2 + (k2-aux)/2 >= b) f2 = 1;

        if (f1 && f2) p("YES");
        else          p("NO");
    }
}
