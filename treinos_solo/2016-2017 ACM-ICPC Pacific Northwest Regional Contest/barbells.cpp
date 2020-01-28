//codeforces.com/gym/101291/attachments

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

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
    vl results((1<<n), 0ll);

    fr(i, (1<<n))
        fr(j, n)
            if ( i & ( 1<<j ))
                results[i] += s[j];

    return results;
}


int main(){
	fastio

    int n, m;
    cin >> n >> m;

    vl b(n);
    vl p(m);
    fr(i, n) cin >> b[i];
    fr(i, m) cin >> p[i];

    set<ll> ans;
    vl aux1;
    vl aux2;
    fr(i, (1<<m)) {

        aux1.clear(); aux2.clear();

        fr(j, m) {

            if (i & (1<<j)) aux1.pb(p[j]);
            else aux2.pb(p[j]);
        }

        aux1 = sum_of_all_subset(aux1);
        aux2 = sum_of_all_subset(aux2);

        sort(all(aux2));
        for (auto x : aux1)
            if (binary_search(all(aux2), x))
                for (auto y : b)
                    ans.insert(x+x+y);
    }

    for (auto a : ans)
        cout << a << "\n";
}
