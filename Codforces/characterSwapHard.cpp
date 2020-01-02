//codeforces.com/contest/1243/problem/B2

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
    int freq[130];

    while (k--) {

        ms(freq, 0);
        
        int n;
        vector<pii> ans;

        cin >> n;
        cin >> s >> t;

        fr(i, n) {
            freq[s[i]]++;
            freq[t[i]]++;
        }

        fr(i, 130) {
            if (freq[i]%2) {
                p("No");
                goto fim;
            }
        }

        fr(i, n) {

            if (s[i] == t[i]) continue;
            int opa = 0;
            
            for (int j = i+1; j < n; j++) 
                if (s[j] == s[i]) {
                    swap(s[j], t[i]);
                    ans.pb({j, i});
                    opa = 1;
                    break;
                }

            if (opa) continue;
            for (int j = i+1; j < n; j++) {
                if (s[i] == t[j]) {
                    swap(s[j], t[j]);
                    ans.pb({j, j});
                    swap(t[i], s[j]);
                    ans.pb({j, i});
                    break;
                }
            } 
        }

        p("Yes");
        p(ans.size());
        for (auto a: ans) 
            cout << a.f+1 << " " << a.s+1 << endl;

        fim: continue;
    }
}
