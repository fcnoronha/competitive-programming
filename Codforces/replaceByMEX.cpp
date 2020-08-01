//codeforces.com/contest/1375/problem/D

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

#define maxn 1009

int a[maxn], aux[maxn], n;

int calc() {
    fr(i, n+2) aux[i] = 0;
    fr(i, n) aux[a[i]] = 1;
    fr(i, n+2) if (aux[i] == 0) return i;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        fr(i, n) cin >> a[i];

        vi ans;
        while (1) {
            int m = calc();
            if (m >= n) break;
            a[m] = m;
            ans.pb(m+1);
        }
    
        fr(i, n) {
            if (a[i] == i) continue;
            int m = calc();
            if (m == i) {
                a[i] = i;
                ans.pb(i+1);
                continue;
            }
            for (int j = i+1; j < n; j++) {
                if (a[j] != i) continue;
                a[j] = calc();
                ans.pb(j+1);
            }
            a[i] = i;
            ans.pb(i+1);
        }
        //fr(i, n) cout << a[i] << "-\n"[i==n-1];

        p(ans.size());
        pv(ans);
    }
}
