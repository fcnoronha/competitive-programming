//codeforces.com/contest/1269/problem/B

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

    int n, m;
    cin >> n >> m;

    int a[n], b[n];
    fr(i, n) cin >> a[i];
    fr(i, n) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);

    int ans = INF, act_a, act_b, pos_x;
    fr(ini, n) {

        act_a = a[ini];
        act_b = b[0];
        
        if (act_a <= act_b) pos_x = act_b - act_a;
        else pos_x = (m-act_a) + act_b;
        
        int idx = ini;
        for (int j = 0; j < n; j++, idx = (idx+1)%n) {

            if (b[j] == act_b && a[idx] == act_a) {
                if ((a[idx]+pos_x)%m == b[j]) continue;
                else goto naodeu;
            }
            if (b[j] == act_b || a[idx] == act_a) goto naodeu;
            act_b = b[j];
            act_a = a[idx];
            if ((a[idx]+pos_x)%m != b[j]) goto naodeu;
        }

        ans = min(ans, pos_x);
        naodeu: continue;
    }

    p(ans);
}
