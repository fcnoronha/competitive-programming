//codeforces.com/contest/1291/problem/D

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

int freq[200009][30];
int main(){
    //fastio;

    string s;
    cin >> s;
    int n = s.size();

    s = "*"+s;


    frr(i, n) {
        fr(j, 26)
            freq[i][j] = freq[i-1][j];
        int j = s[i] - 'a';
        freq[i][j]++;   
    }
    
    int q = 0;
    cin >> q;


    while (q--) {

        int l, r;
        cin >> l >> r;

        if (l == r || s[l] != s[r]) {
            p("Yes");
            continue;
        }

        vi aux(26,0);
        fr(i, 26) aux[i] = freq[r][i] - freq[l-1][i];
        
        int cnt = 0;
        fr(i, 26) if (aux[i]) cnt++;

        if (cnt >= 3) {
            p("Yes");
            continue;
        }

        p("No");    
    }
}
