//codeforces.com/contest/1304/problem/B

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

int main(){
    fastio;
    
    int n, m;
    cin >> n >> m;

    string s[n];
    fr(i, n) cin >> s[i];

    vi used(n, 0);

    deque<string> ans;
    fr(i, n) {

        string a = s[i];

        for (int j = i+1; j < n; j++) {
            string b = s[j];
            reverse(all(b));
            if (a == b) {
                used[i] = used[j] = 1;
                ans.push_front(s[i]);
                ans.push_back(s[j]);
                break;
            }
        }
    }

    string meio = "";
    fr(i, n) {
        if (used[i]) continue;
        int pal = 1;
        for(int j = 0; j < m/2; j++) {
            if (s[i][j] != s[i][m-j-1]) {
                pal = 0;
                break;
            }
        }
        if (pal) {
            meio = s[i];
            break;
        }
    }

    int sz = (int)ans.size();
    if (meio != "") sz++;
    p(sz*m);
    fr(i, sz/2) cout << ans[i];
    cout << meio;
    for (int i = sz/2; i < ans.size(); i++) cout << ans[i];
    cout << endl;
}
