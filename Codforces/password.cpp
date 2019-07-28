//codeforces.com/contest/126/problem/B

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

vi lps;
string pat;

void LPS(int M){

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

int main(){
    fastio

    cin >> pat;
    int n = pat.size();
    lps.resize(n);
    LPS(n);

    if (n < 3 || lps[n-1] == 0) {
        p("Just a legend");
        return 0;
    }

    //pv(lps);

    fr(i, n-1) {

        if (lps[i] == lps[n-1]) {

            fr(j, lps[i])
                cout << pat[j];
            cout << endl;
            return 0;
        }
    }

    if (lps[lps[n-1]-1] == 0) {
        p("Just a legend");
        return 0;
    }

    fr(i, lps[lps[n-1]-1]) {
        cout << pat[i];
    }
    cout << endl;
    return 0;

    p("Just a legend");
}
