//codeforces.com/contest/1262/problem/C

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

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string s, tgt;
        cin >> s;

        fr(i, k-1) tgt += "()";
        int aux = n-tgt.size();
        fr(i, aux/2) tgt += "(";
        fr(i, aux/2) tgt += ")";

        vector<pii> ans;
        fr(i, n-1) {

            if (s[i] == tgt[i]) continue;

            int j = i+1;
            while (s[j] != tgt[i]) j++;
            
            for (int k = 0; k <= (j-i)/2; k++) swap(s[i+k], s[j-k]);
            ans.pb({i+1, j+1});
        }

        p(ans.size());
        for (auto a: ans) cout << a.f << " " << a.s << endl;
    }
}
