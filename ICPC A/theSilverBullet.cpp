//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2168

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

    frr(to, t) {

        int n;
        cin >> n;

        set< pii > pos;
        ld x, y;
        fr(i, n) {
            cin >> x >> y;

            x += 0.00001; y += 0.00001;
            x *= 100.0; y *= 100.0;

            pos.insert({int{x}, int{y}});
        }

        int ans = 0;
        for (auto a : pos) {

            map< pii, int> lines;
            for (auto b : pos) {

                if (a == b) continue;

                int va = (a.s-b.s);
                int vb = (a.f-b.f);
                int g = __gcd(va, vb);
                va /= g; vb /= g;

                lines[{va,vb}]++;
            }

            for (auto x : lines)
                ans = max(ans, x.s+1);
        }

        int qtd = pos.size();

        if (qtd == 1) {
            printf("Data set #%d contains a single gnu.\n", to);
            continue;
        }

        printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", to, qtd, ans);
    }
}
