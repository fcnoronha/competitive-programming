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

    int n;
    while (cin >> n) {

        string str[n];
        fr(i, n) cin >> str[i];

        int cnt_rd = 0, cnt_r = 0, cnt_d = 0;

        int cnt = 0;
        fr(k, n) {

            string s = str[k];

            fr(i, s.size()) {
                if (s[i] == 'D') {
                    for (int j = i+1; j < s.size(); j++) {
                        if (s[j] == 'R') {
                            s[i] = s[j] = '#';
                            cnt++;
                            i = j;
                            break;
                        }
                    }
                }
            }

            int fr = 0, fd = 0;

            string aux = "";
            fr(i, s.size()) {
                if (s[i] == '#') break;
                if (s[i] == 'R') {
                    fr = 1;
                    break;
                }
            }

            for (int i = s.size()-1; i >= 0; i--) {

                if (s[i] == '#') break;
                if (s[i] == 'D') {
                    fd = 1;
                    break;
                }
            }

            if (fr && fd) aux = "RD", cnt_rd++;
            else if (fr) aux = "R", cnt_r++;
            else if (fd) aux = "D", cnt_d++;
            str[k] = aux;
        }

        if (cnt_rd) {
            cnt += cnt_rd-1;
            if (cnt_d) {
                cnt++;
                cnt_d--;
            }
            if (cnt_r) {
                cnt++;
                cnt_r--;
            }
        }

        cnt += min(cnt_r, cnt_d);
        cout << cnt << endl;
    }
}
