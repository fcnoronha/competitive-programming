//codeforces.com/contest/1379/problem/A

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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
    fastio;

    int t;
    cin >> t;
    while (t--) {
        string s, tgt = "abacaba";
        int n;

        cin >> n >> s;

        fr(i, n) {

            string aux = s;
            if (i+7 > n) break;

            int ok = 1;
            fr(j, 7) {
                if (aux[i+j] == '?' || aux[i+j] == tgt[j]) 
                    aux[i+j] = tgt[j];
                else {
                    ok = 0;
                    break;
                }
            } 

            if (!ok) continue;
            fr(j, n) if (aux[j] == '?') aux[j] = 'z';

            if (aux.find(tgt) != aux.rfind(tgt)) continue;
            p("Yes");
            p(aux);
            goto fim;
        }

        p("No");
        fim:;
    }
}
