//codeforces.com/problemset/problem/552/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
	fastio

    int n;
    cin >> n;

    pii cd[n];
    fr(i, n) cin >> cd[i].f >> cd[i].s;

    int ans = 0;
    fr(i, n) {

        // vectors from i-th point to j-th
        map<pii, int> vs;
        int cnt = 0;

        fr(j, n) {

            if (j == 0) {
                j = i;
                continue;
            }

            int a = cd[i].f - cd[j].f;
            int b = cd[i].s - cd[j].s;

            int g = __gcd(a, b);
            a /= g, b /= g;

            // same lines, with the following rule
            // r: (cd[i].f, cd[i].s) + LBD*(a, b)
            vs[{a, b}]++;
            cnt++;
        }

        ans += ((cnt-1)*cnt)/2;

        // taking out equals
        for (auto x : vs)
            ans -= ((x.s-1)*x.s)/2;
    }

    p(ans);
}
