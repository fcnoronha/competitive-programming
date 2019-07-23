//www.spoj.com/problems/SUBSUMS/

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

vl sum_of_all_subset ( vl s ) {

    int n = s.size() ;
    vl results(1<<n, 0ll);

    fr(i, (1<<n))
        fr(j, n)
            if ( i & ( 1<<j ))
                results[i] += s[j];

    return results;
}

int main(){
	fastio

    ll n, a, b;
    cin >> n >> a >> b;

    ll s[n];
    fr(i, n) cin >> s[i];

    // Creating two sets that will store all possible subset sums of the first
    // and second half of s[]
    vl aux, sums1, sums2;
    fr(i, n/2) aux.pb(s[i]);
    sums1 = sum_of_all_subset(aux);

    aux.clear();
    for (int i = n/2; i < n; i++) aux.pb(s[i]);
    sums2 = sum_of_all_subset(aux);

    ll ans = 0ll;
    sort(all(sums2));

    for (auto v : sums1)
        ans += upper_bound(all(sums2), b-v) - lower_bound(all(sums2), a-v);

    cout << ans << endl;
}
