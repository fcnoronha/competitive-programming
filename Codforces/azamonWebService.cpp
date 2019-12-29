//codeforces.com/contest/1281/problem/B

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

        string a, b;
        cin >> a >> b;
        int fnd = 0;
        char lst;

        if (a < b) {
            cout << a << endl;
            goto fim;
        }

        lst = '@';
        fr(i, a.size()-1) {
            
            if (a[i] == lst) continue;           
            for (int j = i+1; j < a.size(); j++) {
                
                if (a[j] < a[i]) {
                   
                    swap(a[j], a[i]);
                    if (a < b) {
                        cout << a << endl;
                        goto fim;
                    }
                    swap(a[j], a[i]);
                }
            }

            lst = a[i];
        }

        cout << "---\n";
        fim: continue; 
    }
}
