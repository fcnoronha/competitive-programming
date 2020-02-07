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

        string p;
        cin >> p;

        int n;
        cin >> n;

        string s;
        cin >> s;
        vi v;
        int aux = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= '0' && s[i] <= '9') {
                aux *= 10;
                aux += s[i]-'0';
                continue;
            } 
            if (aux) v.pb(aux);
            aux = 0;
        }

        vi ans;
        int pos[2] = {0, n-1};
        int idx = 0;
        for (auto cmd: p) {

            if (cmd == 'R') {
                idx = (idx+1)%2;
            }
            else {
                if (pos[0] > pos[1]) {
                    p("error");
                    goto fim;
                }
                if (idx == 0) pos[idx]++;
                else pos[idx]--;
            }
        }

        if (idx == 0)
            for (int i = pos[0]; i <= pos[1]; i++)
                ans.pb(v[i]);

        if (idx == 1)
            for (int i = pos[1]; i >= pos[0]; i--)
                ans.pb(v[i]);

        cout << '[';
        fr(i, ans.size()) {
            cout << ans[i];
            if (i < ans.size()-1) cout << ",";
        }
        cout << "]\n";
        fim:;
    }

}