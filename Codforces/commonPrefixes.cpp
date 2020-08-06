//codeforces.com/contest/1384/problem/A

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

const int sz = 60;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        string ans[n+1];
        int j = 0;

        fr(i, sz) ans[0] += 'a';
        fr(i, n) {
            int x;
            cin >> x;

            fr(k, sz) {
                if (k < x) ans[i+1] += ans[i][k];
                else       ans[i+1] += 'a'+((ans[i][k]-'a')+1)%26 ;
            }

        }

        fr(i, n+1) p(ans[i]);
    }
}
