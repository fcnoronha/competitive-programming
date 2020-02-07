//codeforces.com/contest/1296/problem/E1

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

    int n;
    string s;
    cin >> n >> s;
    
    string ans;
    char l1 = 'a', l2 = 'a';
    for (auto c: s) {
        if (c >= l1) {
            ans += '0';
            l1 = c;
        } 
        else if (c >= l2) {
            ans += '1';
            l2 = c;
        } 
        else {
            p("NO");
            return 0;
        }
    }

    p("YES");
    p(ans);
}
