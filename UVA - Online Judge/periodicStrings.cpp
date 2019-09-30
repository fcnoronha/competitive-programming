//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=396

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
vi lps;
int cnt, N, M;

void LPS(){

    int len = 0; // Tamanho do ultimo prefixo sufixo

    lps[0] = 0; // base

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


void KMP(){

    lps.clear();
    lps.resize(M);
    LPS();

    int i = 0; // index para txt[]
    int j = 0; // index para pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            cnt++;
            j = lps[j - 1];
        }

        // mismatch
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}


int main(){
    //fastio

    int t;
    cin >> t;

    while (t--) {

        cin >> txt;

        N = txt.size();
        M = 0;
        string aux;

        pat.clear();
        fr(i, N) {

            pat += txt[i];
            aux += txt[N-i-1];
            M++;

            if (N%M != 0) continue;

            cnt = 0;
            KMP();

            string auxx = aux;
            reverse(all(aux));

            if (cnt == N/M && pat == aux) {
                p(M);
                if (t) p("");
                break;
            }

            aux = auxx;
        }
    }
}
