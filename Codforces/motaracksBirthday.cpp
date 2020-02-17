//codeforces.com/contest/1301/problem/B

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

        int a[n];
        fr(i, n) cin >> a[i];

        int tudo = 1;
        fr(i, n) if (a[i] != -1) {
            tudo = 0;
            break;
        }
        if (tudo) {
            p("0 0");
            continue;
        }

        set<int> aux;

        int lst = a[0];
        fr(i, n) {

            if (a[i] == -1) {
                if (lst == -1) continue;
                aux.insert(lst);
                lst = -1;
                continue;
            } 
            if (lst == -1) {
                lst = a[i];
                aux.insert(lst);
                continue;
            }

            lst = a[i];
        }

        int k = *aux.rbegin() + *aux.begin();
        k /= 2;
        int m = 0;

        fr(i, n-1) {
            if (a[i] == -1) a[i] = k;
            if (a[i+1] == -1) a[i+1] = k;
            m = max(m, abs(a[i]-a[i+1]));
        }

        cout << m << " " << k << endl;
    }
}
