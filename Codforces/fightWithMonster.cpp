//codeforces.com/contest/1296/problem/D

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

    ll n, a, b, k;
    cin >> n >> a >> b >> k;

    ll h[n];
    fr(i, n) {
        cin >> h[i];
        h[i] %= (a+b);

        if (h[i] == 0) 
            h[i] = a+b;    
        
    }

    ll cnt = 0;
    fr(i, n) {

        if (h[i] > a) continue;

        cnt++;
        h[i] = INF;
    }

    sort(h, h+n);

    fr(i, n) {

        if (h[i] == INF) break;

        h[i] -= a;
        
        ll aux = (h[i]+a-1)/a;
        if (aux > k) break;

        k -= aux;
        cnt++;
    }

    p(cnt);
}
