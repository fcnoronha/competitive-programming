//codeforces.com/contest/1277/problem/C

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

    vector<string> porras = {"twone", "one", "two"};

    while (t--) {

        string s;
        cin >> s;

        vi ans;

        for (auto p: porras) {

            int np = p.size();

            fr(i, (int)s.size()-np+1) {

                for (int j = 0; j < np; j++) 
                    if (s[i+j] != p[j]) goto prox;
            
                if (p == "twone") {
                    ans.pb(i+3);
                    s[i+2] = '#';
                }
                else {
                    ans.pb(i+2);
                    s[i+1] = '#';
                }

                i += np-1;
                prox: continue;
            }
        }
        
        p(ans.size());
        if (ans.size()) pv(ans);
        else p("");
    }
}
