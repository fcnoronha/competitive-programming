//codeforces.com/contest/1282/problem/C

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

    int m;
    cin >> m;

    while (m--) {

        ll n, t, a, b;
        cin >> n >> t >> a >> b;

        pll pr[n+1];
        fr(i, n) cin >> pr[i].s;
        fr(i, n) cin >> pr[i].f;
        pr[n].f = t+1;

        sort(pr, pr+n);

        ll hard = 0, easy = 0;
        fr(i, n) {
            hard += (pr[i].s == 1);
            easy += (pr[i].s == 0);
        }

        ll time_spent = 0, ans = 0, solved = 0;
        fr(i, n+1) {

            ll crt_time = pr[i].f - 1;
            ll time_left = crt_time - time_spent;

            if (time_left >= 0) {

                ll amt_easy = time_left/a;
                amt_easy = min(amt_easy, easy);
                time_left -= amt_easy*a;
            
                ll amt_hard = time_left/b;
                amt_hard = min(amt_hard, hard);
                time_left -= amt_hard*b;

                ans = max(ans, amt_hard+amt_easy+solved);
            }

            int aux = i;
            while (aux <= n && pr[aux].f == pr[i].f) {

                solved++;
                if (pr[aux].s) time_spent += b, hard--;
                else time_spent += a, easy--;
                aux++;
            }
            i = aux-1; 
        }

        p(ans);
    }
}
