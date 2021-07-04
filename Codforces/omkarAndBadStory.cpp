//codeforces.com/contest/1536/problem/A

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;

        vi v(n); fr(i, n) cin >> v[i];

        map<int, bool> has;
        fr(i, n) has[v[i]] = 1;

        queue<int> add;
        fr(i, n) for (int j = i+1; j < n; j++) 
            if (has[abs(v[i]-v[j])] == 0)
                add.push(abs(v[i]-v[j]));

        bool deu = 1;
        while (!add.empty()) {

            int x = add.front();
            add.pop();

            if (has[x]) continue;

            if (v.size() >= 300) {
                deu = 0;
                break;
            }

            for (auto y: v) 
                if (!has[abs(x-y)])
                    add.push(abs(x-y));

            v.pb(x);
            has[x] = 1;
        }

        if (!deu) {
            p("NO");
            continue;
        }

        p("YES");
        p(v.size());
        pv(v);
    }
}
