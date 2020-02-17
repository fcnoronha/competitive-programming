//codeforces.com/contest/1301/problem/D

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

    int n, m, k;
    cin >> n >> m >> k;

    if (k > 4*n*m - 2*n - 2*m) {
        p("NO");
        return 0;
    }

    vector<pair<int, string>> ans;
    int aux;
    
    if (n == 1) {
        aux = min(k, m-1);
        ans.pb({aux, "R"});
        k -= aux;
        if (k) ans.pb({k, "L"});
        goto fim;
    }

    if (m == 1) {
        aux = min(k, n-1);
        ans.pb({aux, "D"});
        k -= aux;
        if (k) ans.pb({k, "U"});
        goto fim;
    }

    frr(c, m) {

        if (c != m) {

            if (k == 0) goto fim;
            aux = min(k, n-1);
            ans.pb({aux, "D"});
            k -= aux;

            if (k == 0) goto fim;
            aux = min(k, n-1);
            ans.pb({aux, "U"});
            k -= aux;
            
            if (k == 0) goto fim;
            ans.pb({1, "R"});
            k--;
            if (k == 0) goto fim;
            continue;        
        }

        // last column
        if (k == 0) goto fim;
        aux = min(k, n-1);
        k -= aux;
        ans.pb({aux, "D"});

        if (k == 0) goto fim;

        frr(r, n) {

            if (r != n) {

                if (k == 0) goto fim;
                aux = min(k, m-1);
                k -= aux;
                ans.pb({aux, "L"});

                if (k == 0) goto fim;
                aux = min(k, m-1);
                k -= aux;
                ans.pb({aux, "R"});

                if (k == 0) goto fim;
                ans.pb({1, "U"});
                k--;
                
                if (k == 0) goto fim;
                continue;
            }

            if (k == 0) goto fim;
            aux = min(k, m-1);
            ans.pb({aux, "L"});
            goto fim;
        }        
    }
    
    fim:;
    p("YES");
    p((int)ans.size());
    for (auto a: ans) 
        cout << a.f << " " << a.s << endl;
}
