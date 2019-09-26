//codeforces.com/contest/1215/problem/A

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

    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    int mx, mn;

    // k1 smaller
    if (k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }

    int aux = n/k1;
    aux = min(aux, a1);
    mn = aux;
    aux = n - aux*k1;
    aux /= k2;
    mn += aux;

    int cnt = (k2-1)*a2 + (k1-1)*a1;
    if (cnt >= n)
        mx = 0;
    else {
        n -= cnt;
        mx = n;
    }

    cout << mx << " " << mn << endl;
}
