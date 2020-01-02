//codeforces.com/contest/1243/problem/B1

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

    int k;
    cin >> k;

    string s, t;

    while (k--) {

        vi idx;
        
        int n;
        cin >> n;
        cin >> s >> t;

        fr(i, n) 
            if (s[i] != t[i]) 
                idx.pb(i);
        
        int i1, i2, pos;
        if (idx.size() > 2) {
            p("No");
            goto fim;
        }

        if (idx.size() == 1) {
            pos = idx[0];
            swap(s[pos], t[pos]);
            
            if (s == t) p("Yes");
            else p("No");
            
            goto fim;
        }

        i1 = idx[0];
        i2 = idx[1];
        if(s[i1] == s[i2] && t[i1] == t[i2]) p("Yes");
        else p("No");
    
        fim: continue;
    }
}
