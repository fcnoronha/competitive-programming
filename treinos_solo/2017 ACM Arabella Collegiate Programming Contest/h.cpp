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

char lt[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
bool top[26];

int main() {
    fastio;

    int t;
    cin >> t;

    fr(i, 11) top[lt[i]-'A'] = 1; 

    while (t--) {
        string s;
        cin >> s;

        int deu = 1;
        for (auto c: s) 
            if (!top[c-'A']) deu = 0;
        
        for (int i = 0; i < s.size()/2; i++) 
            if (s[i] != s[s.size()-i-1]) 
                deu = 0;
        
        if (!deu) {
            p("no");
            continue;
        }
        p("yes");
    }
}
