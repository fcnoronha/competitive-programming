//codeforces.com/contest/1307/problem/C

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

    string s;
    cin >> s;

    vl freq(26, 0ll);
    for (auto c: s) 
        freq[c-'a']++;
    
    ll ans = 0ll;
    fr(i, 26) ans = max(ans, freq[i]);

    map<pair<char, char>, ll> mp;
    fr(i, (int)s.size()) {
        char c = s[i];
        freq[c-'a']--;
        for (char l = 'a'; l <= 'z'; l++) 
            mp[{c,l}] += freq[l-'a'];
    }

    for (auto x: mp) ans = max(ans, x.s);

    p(ans);
}
