//codeforces.com/contest/1335/problem/D

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

pii pos[] = {{0,0},{1,3},{2,6},{3,1},{4,4},{5,7},{6,2},{7,5},{8,8}};
int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        string sd[9];
        fr(i, 9) cin >> sd[i];
        fr(k, 9) {
            int i = pos[k].f;
            int j = pos[k].s;
            if (sd[i][j] == '1') sd[i][j] = '2';
            else sd[i][j]--;
        }
        fr(i, 9) p(sd[i]);
    }
}
