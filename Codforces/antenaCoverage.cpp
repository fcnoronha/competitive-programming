//codeforces.com/contest/1253/problem/E

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

    int n, m;
    cin >> n >> m;

    vector<pii> ant;
    int x, s;
    fr(i, n) {

        cin >> x >> s;

        int l = max(0, x-s);
        int r = min(m, x+s);
        ant.pb({l, r});
    }


    int pd[m+1];
    pd[m] = 0;
    
    for (int pos = m-1; pos >= 0; pos--) {

        pd[pos] = m-pos;

        for (auto a: ant) {

            if (a.f <= pos+1 && pos+1 <= a.s) {
                pd[pos] = pd[pos+1];
                break;
            }

            if (pos < a.f) {

                int cst = a.f - pos - 1;
                int npos = min(m, a.s+cst);
                pd[pos] = min(pd[pos], cst+pd[npos]);
            }
        }
    }

    p(pd[0]);
}