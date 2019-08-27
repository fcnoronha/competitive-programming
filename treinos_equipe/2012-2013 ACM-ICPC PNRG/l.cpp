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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int nv = 6, nc = 20;

vector<char> v = {'a', 'i', 'y', 'e', 'o', 'u'};
vector<char> c = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

int isV(char oi) {
    fr(i, nv)
        if (oi == v[i])
            return i;
    return -1;
}

int isC(char oi) {
    fr(i, nc)
        if (oi == c[i])
            return i;
    return -1;
}

int main(){
    fastio

    string s;
    while (getline(cin, s)) {

        fr(i, s.size()) {

            bool ms = false;
            if (s[i] >= 65 && s[i] <= 90) {
                s[i] = tolower(s[i]);
                ms = true;
            }

            int idx = isV(s[i]);
            if (idx >= 0) {
                s[i] = v[(idx-3+nv)%nv];
                if (ms) s[i] = toupper(s[i]);
                continue;
            }

            idx = isC(s[i]);
            if (idx >= 0) {
                s[i] = c[(idx-10+nc)%nc];
                if (ms) s[i] = toupper(s[i]);
                continue;
            }
        }

        p(s);
    }
}
