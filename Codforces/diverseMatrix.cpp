//codeforces.com/contest/1266/problem/C

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

    int r, c;
    cin >> r >> c;

    if (r==1 && c==1) {
        p("0");
        return 0;
    }

    int ans[r][c], rm[r], cm[c];

    int lst = 1;
    fr(i, r){
        rm[i] = lst++; 
    }

    fr(i, c){
        cm[i] = lst++; 
    }

    if (c == 1) {
        for (int i = 2; i <= r+1; i++) p(i);
        return 0;
    }

    fr(i, r) {
        fr(j, c) {
            ans[i][j] = rm[i]*cm[j];
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
