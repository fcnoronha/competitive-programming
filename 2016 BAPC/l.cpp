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

bool check(ll a, ll b, ll c) {

  if (a+b <= c) return false;
  if (a+c <= b) return false;
  if (c+b <= a) return false;
  return true;
}

int main(){
    fastio

    ll n;
    cin >> n;

    vl s(n);
    fr(i, n) cin >> s[i];

    sort(all(s));
    fr(i, n) {
      fr(j, n) {

        if (i == j) continue;
        int it = (lower_bound(all(s), s[i]+s[j]) - s.begin());
        int it2 = (lower_bound(all(s), abs(s[i]-s[j])) - s.begin());
        for (int k = it; k >= max(it2, 0); k--) {
          if (k == j || k == i) continue;
          if (check(s[i], s[j], s[k])) {
            p("possible");
            return 0;
          }
        }
      }
    }
    p("impossible");
}
