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

char pos[3] = {'a', 'b', 'c'};

int main(){
    
    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        if (s == "?") {
            p('a');
            continue;
        }

        fr(i, s.size()-1) 
            if (s[i] == s[i+1] && s[i] != '?') {
                p(-1);
                goto FIM;
            }

        fr(i, s.size()+1) {
            if (i == s.size()) {
                p(s);
                goto FIM;
            }
            if (s[i] == '?') break;
        }

        frr(i, s.size()-2) 
            if (s[i] == '?')
                fr(j, 3) {
                    if (s[i-1] == pos[j] || s[i+1] == pos[j]) continue;
                    s[i] = pos[j];
                    break;
                }
        
        if (s[0] == '?')
            fr(j, 3) {
                if (s[1] == pos[j]) continue;
                s[0] = pos[j];
                break;
            }

        if (s[s.size()-1] == '?')
            fr(j, 3) {
                if (s[s.size()-2] == pos[j]) continue;
                s[s.size()-1] = pos[j];
                break;
            }

        p(s);
        FIM: continue;
    }
}
