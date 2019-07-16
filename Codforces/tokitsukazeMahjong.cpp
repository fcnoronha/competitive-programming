//codeforces.com/contest/1191/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    map<string, int> mp;
    int cnt = 1;

    for (string i = "1"; i <= "9"; i[0]++) {
        mp[i + "m"] = cnt;
        mp[i + "p"] = cnt+20;
        mp[i + "s"] = cnt+40;

        cnt++;
    }

    vi aux = vi({mp[s1], mp[s2], mp[s3]});
    sort(all(aux));

    int ans = 2;
    if (aux[0] == aux[1] && aux[1] == aux[2])
        ans = 0;

    if (aux[0]+1 == aux[1] && aux[1]+1 == aux[2])
        ans = 0;

    if (aux[0]+1 == aux[1] || aux[1]+1 == aux[2])
        ans = min(ans, 1);

    if (aux[0] == aux[1] || aux[1] == aux[2])
        ans = min(ans, 1);

    if (aux[0]+2 == aux[1] || aux[1]+2 == aux[2])
        ans = min(ans, 1);

    cout << ans << endl;
}
