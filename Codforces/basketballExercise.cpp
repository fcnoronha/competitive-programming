//codeforces.com/contest/1195/problem/C

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

    ll n;
    cin >> n;

    vl h(2*n + 10), pd(2*n + 10, 0ll);
    int cnt = 6;
    fr(i, n) cin >> h[cnt], cnt+=2;
    cnt = 7;
    frr(i, n) cin >> h[cnt], cnt+=2;

    fr(i, cnt-1 ) {

        if (i == 0) i = 6;

        pd[i] = h[i];
        if ( i%2 == 0 ) pd[i] += max(pd[i-1], pd[i-3]);
        else pd[i] += max(pd[i-3], pd[i-5]);
    }

    p(*max_element(all(pd)));
}
