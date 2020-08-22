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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;

        int n = s.size(), nd = 0;

        int j = -1;
        fr(i, n) if (s[i] == '.') j = i;
        for (int i = j+1; i < n; i++) nd++;
        int dec = stoi("0" + s.substr(j+1, nd));

        if (j == -1 || nd == 0 || dec == 0) {
            string ss;
            for (auto c: s) {
                if (c == '.') break;
                ss += c;
            }
            cout << ss << "\"\n";
            continue;
        }
        
        int it = stoi("0" + s.substr(0, j));

        long double pw = 1.0;
        fr(i, nd) pw *= 10.0;
        //cout << setprecision(6) << fixed << (stod(s)*pw) << endl;

        int a, b, deu = 0;
        for (b = 2; b <= 128; b<<=1) {
            for (a = 1; a <= 128; a++) {
                long double aux = ((long double)(a)*pw)/(long double)(b);
                if (dec == (int)(aux+0.0000009) || dec == (int)(aux+0.9999999)) {
                    deu = 1;
                    break;
                }
            }
            if (deu) break;
        }

        if (it) cout << it << ' ';
        cout << a << '/' << b << "\"\n"; 
    }   
}
