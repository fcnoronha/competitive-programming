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

#define maxn 212345

int n, z, v[maxn], usd[maxn];

int f(int mid) {

    ms(usd, 0);

    int l = 0, r = mid, ans = 0;
    while (r < n && l < mid) {

        while (v[r]-v[l] < z) {
            r++;
            if (r == n) return ans;
        }

        ans++;
        usd[l] = usd[r] = 1;
        l++, r++;
        while (l < mid && usd[l]) l++;
        while (r < n && usd[r]) r++;
    }

    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> n >> z;

    fr(i, n) cin >> v[i];
    sort(v, v+n);

    int l = 0, r = n-1;
    while (l < r) {

        int m1 = l + (r-l) / 3;
        int m2 = r - (r-l) / 3;

        int f1 = f(m1); 
        int f2 = f(m2);

        // dbg(f1);
        if (f1 < f2) l = m1+1;
        else         r = m2-1;
    }

    p(f(l));
}
