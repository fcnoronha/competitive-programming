//codeforces.com/contest/1283/problem/E

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

#define maxn 200009
int x[maxn], xo[maxn];

int main(){
    fastio;

    int n;
    cin >> n;

    fr(i, n) {
        int aux;
        cin >> aux;
        
        x[aux]++;
        xo[aux]++;
    }

    int mn = 0;
    for (int i = 1; i <= n+1;) {

        if (!xo[i]) {
            i++;
            continue;
        }

        i++;
        
        xo[i] = xo[i-1] = xo[i+1] = 0;
        mn++;
        
        i++;
    }

    int mx = 0;
    fr(i, n+3) {

        if (i > 0 && x[i-1]) {
            x[i-1]--;
            mx++;
            continue;
        } 
        
        if (x[i]) {
            mx++;
            x[i]--;
            continue;
        }

        if (x[i+1]) {
            x[i+1]--;
            mx++;
        }
    }
    
    cout << mn << " " << mx << endl;
}
