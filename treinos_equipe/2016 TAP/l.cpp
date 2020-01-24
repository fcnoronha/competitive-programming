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

    int n, k;
    while(cin >> n >> k) {

        int a[k];
        fr(i, k) cin >> a[i];

        int idx = 0;
        int crec = 0, dec = 0;
        frr(i, k-1) {

            int d = abs(a[i]-a[i-1]);
            if (d == 0 || d > 2) {
                p("N");
                goto fim;
            }
            
            if (a[i] > a[i-1]) {
                crec = 1;
                if (dec) {
                    p("N");
                    goto fim;
                }
            }

            if (a[i] < a[i-1]) {
                dec = 1;
            }

            if (a[i] == 1 && a[i-1] == 2) {
                p("N");
                goto fim;
            }

            if (a[i] == 2 && a[i-1] == 1) {
                p("N");
                goto fim;
            }
        }

        fr(i, k) if (a[i] > a[idx]) idx = i;

        if (idx != 0 && idx != k-1) {
            if (a[idx-1] == a[idx+1]) {
                p("N");
                goto fim;
            }
        }
        
        p("S");
        fim:;
    }
}
