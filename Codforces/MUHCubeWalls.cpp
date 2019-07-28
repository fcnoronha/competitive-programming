//codeforces.com/contest/471/problem/D

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

vi pat, txt, lps;
int N, M, cnt;

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
    fastio

    cin >> N >> M;

    txt.resize(N);
    pat.resize(M);

    for (auto &x : txt) cin >> x;
    for (auto &x : pat) cin >> x;

    N--;
    M--;

    if (!M) {
        p((N+1));
        return 0;
    }

    vi aux;
    fr(i, N)
        aux.pb(txt[i] - txt[i+1]);
    txt = aux;

    vi auxx;
    fr(i, M)
        auxx.pb(pat[i] - pat[i+1]);
    pat = auxx;

    KMP();

    p(cnt);
}
