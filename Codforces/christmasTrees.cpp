//codeforces.com/contest/1283/problem/D

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

    int n, m;
    cin >> n >> m;

    int x[n];
    fr(i, n) cin >> x[i];

    int y[m];
    ms(y, 0);

    map<int, bool> used;
    set< pair< pii, int > > avlb; // {{dist, pos}, direction}

    fr(i, n) {

        avlb.insert({{1, x[i]+1}, +1});
        avlb.insert({{1, x[i]-1}, -1});
        used[x[i]] = 1;
    }

    ll ans = 0ll;
    fr(i, m) {

        auto aux = *avlb.begin();
        avlb.erase(aux);

        while (used[aux.f.s]) {
            aux = *avlb.begin();
            avlb.erase(aux);
        }

        y[i] = aux.f.s;
        used[aux.f.s] = 1;

        int d = aux.s;
        avlb.insert({{aux.f.f+1, aux.f.s+d}, d});

        ans += ll(aux.f.f);
    }

    p(ans);
    fr(i, m) cout << y[i] << " ";
    cout << endl;
}
