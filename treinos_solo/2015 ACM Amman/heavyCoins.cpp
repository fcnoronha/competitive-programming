//codeforces.com/gym/100712/attachments

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

    int t;
    cin >> t;

    while (t--) {

        int n, s;
        cin >> n >> s;

        vi c(n);
        fr(i, n) cin >> c[i];

        sort(all(c));
        reverse(all(c));

        pii ans = {0, 0};
        fr(i, (1<<n)) {

            pii aux = {0, 0};
            fr(j, n)
                if (i & (1<<j)) {
                    aux.f++;
                    aux.s += c[j];

                    if (aux.s >= s) break;
                }

            if (aux.s < s) continue;
            ans = max(ans, aux);
        }

        // dbg(ans.s);
        p(ans.f);
    }
}
