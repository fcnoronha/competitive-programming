//codeforces.com/contest/1536/problem/B

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
        string s; cin >> s;
        s += "&&&";

        map<string, bool> has;
        fr(i, n) {
            
            string a = "";
            a += s[i];
            has[a] = 1;

            a += s[i+1];
            has[a] = 1;

            a += s[i+2];
            has[a] = 1;    
        }

        char a, b, c;
        string h;
        for (a = 'a'; a <= 'z'; a++) {
            h = ""; h += a;
            if (!has[h]) {
                p(h);
                goto fim;
            }   
        }

        for (a = 'a'; a <= 'z'; a++) for (b = 'a'; b <= 'z'; b++) {
            h = ""; h += a; h += b;
            if (!has[h]) {
                p(h);
                goto fim;
            }
        } 
        
        for (a = 'a'; a <= 'z'; a++) for (b = 'a'; b <= 'z'; b++) for (c = 'a'; c <= 'z'; c++) {
            h = ""; h += a; h += b; h+= c;
            if (!has[h]) {
                p(h);
                goto fim;
            }
        }

        fim:;
    }
}
