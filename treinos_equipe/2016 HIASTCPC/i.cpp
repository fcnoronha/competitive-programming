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

    int t;
    cin >> t;

    while (t--) {

        string s1, s2;
        cin >> s1 >> s2;

        map<char, int> mp;
        fr(i, s1.size())
            mp[s1[i]]++;

        fr(i, s2.size())
            mp[s2[i]]--;

        int ans = 0;
        for (auto x : mp)
            ans += abs(x.s);

        p(ans);
    }
}
