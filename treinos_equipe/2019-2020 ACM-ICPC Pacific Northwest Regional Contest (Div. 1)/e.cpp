#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, n) for (int i = 1; i <= n; i++)
#define ms(x, i) memset(x, i, sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define olar cout << "olar" << endl
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define int long long int
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<vector<int>, vector<int>> parzao;
const int INF = 1e18;

signed main()
{
    fastio;
    string s;
    cin >> s;
    unordered_set<char> letras;
    unordered_map<char, int> cnt;
    vector<char> v;
    int n = s.size();
    for(int i = 0; i<n; i++){
        letras.insert(s[i]);
        cnt[s[i]]++;
    }
    int MOD = 11092019;
    int ans = 1;
    for(auto x : letras){
        ans = (ans * (cnt[x] + 1))%MOD;
    }
    cout << ans%MOD << endl;
}