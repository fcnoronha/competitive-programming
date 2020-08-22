//codeforces.com/contest/1393/problem/B

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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n;
    cin >> n;

    map<int, int> amt;

    int c2 = 0, c4 = 0, c6 = 0, c8 = 0;
    fr(i, n) {
        int x;
        cin >> x;
        amt[x]++;

        if (amt[x] == 8) c8++, c6--;
        if (amt[x] == 6) c6++, c4--;
        if (amt[x] == 4) c4++, c2--;
        if (amt[x] == 2) c2++;
    }

    int q;
    cin >> q;
 
    while (q--) {

        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            amt[x]++;
            if (amt[x] == 8) c8++, c6--;
            if (amt[x] == 6) c6++, c4--;
            if (amt[x] == 4) c4++, c2--;
            if (amt[x] == 2) c2++;
        }
        else {
            if (amt[x] == 8) c8--, c6++;
            if (amt[x] == 6) c6--, c4++;
            if (amt[x] == 4) c4--, c2++;
            if (amt[x] == 2) c2--;
            amt[x]--;
        }

        if ((c8) || 
            (c6 && c2) || 
            (c6 && c4) ||
            (c4 && c2 >= 2) || 
            (c4 >= 2) || 
            (c6 >= 2)) 
            p("YES");
        else p("NO");
    }
}
