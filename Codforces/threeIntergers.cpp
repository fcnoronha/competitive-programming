//codeforces.com/problemset/problem/1311/D

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

int A, B, C;
int dans = INF;
vi ans = vi({0,0,0});

void upd(int a, int b, int c) {
    if (a > b || a > c || b > c) return;
    int d = abs(a-A)+abs(b-B)+abs(c-C);
    if (d < dans) {
        dans = d;
        ans = {a,b,c};
    }
} 

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        dans = INF;
        cin >> A >> B >> C;
    
        for (int a = 1; a <= A+A; a++) {
            int b = a;
            while (b <= B+B) {
                int c = (C/b)*b;
                upd(a,b,c);
                upd(a,b,c+b);
                b += a;
            } 
        }

        p(dans);
        pv(ans);
    }
}
