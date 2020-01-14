//codeforces.com/contest/1287/problem/B

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

    int n, k;
    cin >> n >> k;

    string s[n];
    fr(i, n) cin >> s[i];

    map<string, int> amt;
    fr(i, n) {
        for (int j = i+1; j < n; j++) {

            string aux;
            fr(pos, k) {

                auto c = 'S' + 'E' + 'T' - s[j][pos] - s[i][pos];
                if (s[i][pos] == s[j][pos]) aux += s[i][pos];
                else aux += c;
            }

            amt[aux]++;
        }
    }

    int ans = 0;
    fr(i, n) ans += amt[s[i]];

    p(ans/3);
}
