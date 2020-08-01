//codeforces.com/gym/101806

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

int d1[10003], d2[10003];
char pal[10009];
int n = 0;

int pal_cnt() {
    int ret = 0ll;
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && pal[i - k] == pal[i + k]) {
            k++;
        }
        d1[i] = k--;
        ret += d1[i];
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && pal[i - k - 1] == pal[i + k]) {
            k++;
        }
        d2[i] = k--;
        ret += d2[i];
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }

    return ret;
}

int main() {
    fastio;

    int q;
    cin >> q;

    string qs;
    cin >> qs;

    for (auto c: qs) {
        if (c == '-') {
            n--;
            cout << pal_cnt() << " ";
            continue;
        }
        pal[n++] = c;
        cout << pal_cnt() << " ";
    }
    cout << endl;
}
