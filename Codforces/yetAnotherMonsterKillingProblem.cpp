//codeforces.com/contest/1257/problem/D

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

        int mt[n], bst[n+3];
        fr(i, n) cin >> mt[i];

        int m;
        cin >> m;

        ms(bst, 0);
        fr(i, m) {

            int p, s;
            cin >> p >> s;

            bst[s] = max(bst[s], p);
        }

        for (int i = n-1; i >= 0; i--) 
            bst[i] = max(bst[i], bst[i+1]);

        int l = 0, r = 0, ans = 0, deu = 1;
        while (r < n) {

            ans++;
            int aux = mt[l];
            while (1) {

                aux = max(aux, mt[r]);
                if (bst[r-l+1] < aux) break;
                r++;
            }

            if (l == r) {
                deu = 0;
                break;
            }

            l = r;
        }

        if (deu) p(ans);
        else p("-1");
    }
}
