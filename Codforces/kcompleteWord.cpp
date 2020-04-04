//codeforces.com/contest/1332/problem/C

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

        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        int ans = 0;
        fr(ini, k) {

            map<char, int> cnt;
            for (int i = ini; i < s.size(); i += k) {
                cnt[s[i]]++;
                int pali = n-i-1;
                if (pali%k == ini) continue;
                cnt[s[pali]]++;
            }

            int total = 0, mx = 0;
            char bst;
            for (auto x: cnt) {
                total += x.s;
                if (x.s > mx) {
                    mx = x.s;
                    bst = x.f;
                }
            }

            for (int i = ini; i < s.size(); i += k) {
                s[i] = bst;
                int pali = n-i-1;
                if (pali%k == ini) continue;
                s[pali] = bst;
            }

            ans += total-mx;
        }

        p(ans);
    }
}
