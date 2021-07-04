#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

int cnt = 0;
int ask(int x) {
    cout << "? " << x << endl;
    cin >> x;

    cnt++; assert(cnt <= 100);
    return x;   
}

int val[112345];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    int l = 1, r = n;
    while (l < r) {

        int m1 = (l+r)/2;
        int m2 = m1+1;

        if (val[m1] == 0) val[m1] = ask(m1);
        if (val[m2] == 0) val[m2] = ask(m2);

        if (val[m1] > val[m2]) l = m2;
        else                   r = m1;
    }

    cout << "! " << l << endl;
}
