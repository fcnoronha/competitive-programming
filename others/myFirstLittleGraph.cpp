//www.urionlinejudge.com.br/judge/en/problems/view/2822

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

#define maxn 100009

ll bit[maxn][2], val[maxn];
ll n, q;

ll query(int p, int j) {
    ll sum = 0;
    for (; p > 0; p -= p&-p)
        sum += bit[p][j];
    return sum;
}

void update(int p, ll val, int j) {
    for (; p <= maxn; p += p&-p)
        bit[p][j] += val;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        multiset<ll> mt;

        cin >> n >> q;
        
        fr(i, n+5) bit[i][0] = bit[i][1] = 0;
        frr(i, n) {
            update(i, 1, 0); // 0 => counter
            update(i, i, 1); // 1 => sum
            val[i] = i;
            mt.insert(i);
        }

        ll op, i, k;
        while (q--) {

            cin >> op;

            if (op == 2) {

                if (n <= 1) {
                    p("0");
                }

                ll mn = *mt.begin();
                ll mx = *mt.rbegin();
                ll mid = (mn+mx)/2;

                ll amt = query(mid, 0);
                ll sm = query(mid, 1);

                ll ans = mx - mn;
                ans += (amt-1)*mx - (sm-mn);  

                sm = query(n, 1) - sm;
                amt = n-amt-1;
                ans += sm-mx - amt*mn;

                p(ans);
                continue;
            }

            cin >> i >> k;

            update(val[i], -1, 0);
            update(val[i], -val[i], 1);
            mt.erase(mt.find(val[i]));
            
            val[i] = k;
            
            update(val[i], 1, 0);
            update(val[i], val[i], 1);
            mt.insert(val[i]);
        } 
    }
}
