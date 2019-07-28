//www.spoj.com/problems/NAJPF

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

string pat, txt;
int lps_v[1000009];
vi ans;

void lps(int M){

    int len = 0; // Tamanho do ultimo prefixo sufixo

    lps_v[0] = 0; // base

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps_v[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps_v[len - 1];
            else {
                lps_v[i] = 0;
                i++;
            }
        }
    }
}


void kmp(){
    int M = pat.size();
    int N = txt.size();

    lps(M);

    int i = 0; // index para txt[]
    int j = 0; // index para pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            ans.pb((i-j+1));
            j = lps_v[j - 1];
        }

        // mismatch
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps_v[j - 1];
            else
                i = i + 1;
        }
    }
}


int main(){
    fastio

    int t;
    cin >> t;

    while (t--) {

        cin >> txt >> pat;

        ans.clear();
        kmp();

        if (!ans.size()) {
            p("Not Found\n");
            continue;
        }

        p(ans.size());
        pv(ans);
        if (t>0) p("");
    }
}
