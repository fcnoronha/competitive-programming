//codeforces.com/contest/1327/problem/C

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

#define maxn 300

pii pos[maxn], dst[maxn];
bool seen[maxn];

int dist(pii a, pii b) {
    return abs(a.f-b.f)+abs(a.s-b.s);
}

pii delta(pii a, pii b) {
    return make_pair(b.f-a.f, b.s-a.s);
}

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    fr(i, k) cin >> pos[i].f >> pos[i].s;
    fr(i, k) cin >> dst[i].f >> dst[i].s;

    string ans;

    fr(i, n-1) ans += 'U';
    fr(i, m-1) ans += 'R';

    fr(i, m) {

        if (i%2 == 0) {
            fr(j, n-1) ans += 'D'; 
        } else {
            fr(j, n-1) ans += 'U'; 
        }
        ans+='L';
    }

    p(ans.size());
    p(ans);
}