//codeforces.com/contest/1257/problem/C

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

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int a[n];
        fr(i, n) cin >> a[i];

        if (n <= 1) {
            p("-1");
            continue;
        }

        int lst[n+3];
        ms(lst, -1);

        int lst_check = -1, ans = INF;
        fr(i, n) {

            int last = lst[a[i]];
            lst[a[i]] = i;

            if (last == -1) continue;

            if (lst_check >= last) continue;
            lst_check = last;

            if ((i - last + 1) >= ans) continue; 

            ans = min(ans, (i - last + 1)); 
        }

        if (ans == INF) ans = -1;

        p(ans);
    }
}
