//codeforces.com/contest/1269/problem/C

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

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int a[n];
    fr(i, n) a[i] = s[i]-48;

    int ans[n+2];
    ms(ans, 0);

    fr(i, k+1) {
        if (i == k) {
            p(n);
            p(s);
            return 0;
        } 
        int at = a[i], end = 0;
        for (int j = i; j < n; j += k) 
            if (a[j] != a[i])
                end = 1;
        if (end) break;
    }
    
    fr(i, min(k, n)) {
        int rep = a[i];
        for (int j = i; j < n; j += k) ans[j] = rep;
    }

    int ta_certo = 1;
    fr(i, n) {
        if (ans[i] > a[i]) break;
        if (ans[i] < a[i]) ta_certo = 0;
    }

    if (ta_certo) {
        p(n);
        fr(i, n) cout << ans[i];
        cout << endl;
        return 0;
    }

    for (int i = min(n-1, k-1); i >= 0; i--) {

        int rep = ans[i];
        if (rep < 9) {
            rep++;
            for (int j = i; j < n; j += k) ans[j] = rep;
            
            for (int j = i+1; j < min(n, k); j++) 
                for (int h = j; h < n; h += k) ans[h] = 0;

            break;
        }
    }
    

    p(n);
    fr(i, n) cout << ans[i];
    cout << endl;
}
