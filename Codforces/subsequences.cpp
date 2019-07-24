//codeforces.com/contest/597/problem/C

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

ll bit[12][100009];

ll fact(ll x) {
    if (x <= 1ll) return 1ll;
    return x*fact(x-1ll);
}

ll query(int i, int d){
	ll sum = 0;
    for (; i > 0; i -= i&-i)
    	sum += bit[d][i];
    return sum;
}

void update(ll x, int i, int d){
	for (; i <= 100007; i += i&-i)
		bit[d][i] += x;
}

int main(){
    fastio

    ll n, k, ans = 0ll;
    cin >> n >> k;
    k++;

    ll x;
    fr(i, n) {

        cin >> x;

        update(1ll, x, 1);
        for (int j = 2; j <= k; j++) {
            ll aux = query(x-1, j-1);
            update(aux, x, j);
        }
    }

    p(query(n+1, k));
}
