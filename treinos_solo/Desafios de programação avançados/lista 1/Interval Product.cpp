#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

#define maxn 112345

struct Bit {

    int bit[maxn];

    // [1, i] sum query
    int query(int i){
        int sm = 0;
        for (; i > 0; i -= i&-i) sm += bit[i];
        return sm;
    }

    // sum x on position i
    void update(int i, int x){
        for (; i <= maxn; i += i&-i) bit[i] += x;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    Bit btz, btn;

    int n, k;
    while (cin >> n >> k) {

        fr(i, n+10) btz.bit[i] = btn.bit[i] = 0;

        frr(i, n) {
            int x; cin >> x;
            if (x == 0) btz.update(i, 1);
            if (x < 0) btn.update(i, 1);
        }

        while (k--) {
            
            char op; cin >> op;

            if (op == 'C') {
                int i, x; cin >> i >> x;

                if (btz.query(i) - btz.query(i-1)) {
                    btz.update(i, -1);
                }
                if (btn.query(i) - btn.query(i-1)) {
                    btn.update(i, -1);
                }

                if (x == 0) btz.update(i, 1);
                if (x < 0) btn.update(i, 1);
            }

            else {
                int i, j; cin >> i >> j;

                if (btz.query(j) - btz.query(i-1)) cout << 0;
                else if ((btn.query(j) - btn.query(i-1))%2) cout << "-";
                else cout << "+";
            }
        }
        cout << endl;
    }
}
