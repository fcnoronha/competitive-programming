//codeforces.com/contest/1263/problem/B


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

        int n;
        cin >> n;

        string pin[n];
        map<string, int> mp;
        fr(i, n) cin >> pin[i], mp[pin[i]]++;

        int ans = 0;
        fr(i, n) {

            if (mp[pin[i]] == 1) continue;

            string aux = pin[i];
            mp[aux]--;  

            fr(j, 4) {
                for (char c = '0'; c <= '9'; c++) {
                    string auxx = aux;
                    auxx[j] = c;
                    if (mp[auxx] == 0) {
                        aux = auxx;
                        ans++;
                        goto DEU;
                    }
                }
            }

            fr(j, 4) {
                for (char c = '0'; c <= '9'; c++) {
                    fr(l, 4) {
                        if (j == l) continue;
                        for (char d = '0'; d <= '9'; d++) {
                            string auxx = aux;
                            auxx[j] = c;
                            auxx[l] = d;
                            if (mp[auxx] == 0) {
                                aux = auxx;
                                ans += 2;
                                goto DEU;
                            }
                        }
                    }
                }
            }

            DEU: mp[aux]++;
            pin[i] = aux;
        }

        p(ans);
        fr(i, n) p(pin[i]);
    }
}
