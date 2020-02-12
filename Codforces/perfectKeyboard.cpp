//codeforces.com/contest/1303/problem/C

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

bool used[30];
set<int> adj[30];

void dfs(int i) {

    used[i] = 1;
    cout << char(i+'a');
    
    for (auto c: adj[i]) {
        if (used[c]) continue;
        dfs(c);
    }
}

int main(){
    fastio;

    int t;
    cin >> t;

    string alpha;
    for (char c = 'a'; c <= 'z'; c++) alpha += c;

    while (t--) {
        
        fr(i, 28) {
            used[i] = 0;
            adj[i].clear();
        }

        string s;
        cin >> s;

        int n = (int)s.size();

        if (n == 1) {
            p("YES");
            p(alpha);
            continue;
        }

        vi v(n);
        fr(i, n) 
            v[i] = int(s[i]-'a');

        fr(i, n) {
            if (i) adj[v[i]].insert(v[i-1]); 
            if (i < n-1) adj[v[i]].insert(v[i+1]);
        }

        int tem = 0;
        fr(i, 26) {
            if (adj[i].size() > 2) {
                tem = 0;
                break;
            }
            if (adj[i].size() == 1) 
                tem++;
        }

        if (tem != 2) {
            p("NO");
            continue;
        }

        p("YES");
        fr(i, 26) {
            if (used[i]) continue;
            if ((int)adj[i].size() != 1) continue;
            dfs(i);
            break;
        }
        fr(i, 26) if (!used[i]) cout << alpha[i];
        cout << endl;   
    }
}
