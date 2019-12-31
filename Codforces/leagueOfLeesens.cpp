//codeforces.com/contest/1255/problem/C

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

#define maxn 100009

int freq[maxn];
int q[maxn][3];
int ans[maxn], seen_q[maxn], seen_p[maxn];
vi rev_q[maxn];

int main(){
    fastio;

    int n;
    cin >> n;

    fr(i, n-2) 
        fr(j, 3) {
            cin >> q[i][j];
            freq[q[i][j]]++;
            rev_q[q[i][j]].pb(i);
        } 

    frr(i, n) {
        
        if (freq[i] != 1) continue;
        
        ans[0] = i;
        seen_p[i] = 1;

        int ftq = rev_q[i][0];
        fr(j, 3) {
            int x = q[ftq][j];
            if (freq[x] == 2) {
                ans[1] = x;
                seen_p[x] = 1; 
            }
            if (freq[x] == 3) {
                ans[2] = x;
                seen_p[x] = 1; 
            }
        }
        seen_q[ftq] = 1;
        break;
    }


    int act = 1, idx = 3;
    while (act < n) {
        for (auto x: rev_q[ans[act]]) {
            
            if (seen_q[x]) continue;
            
            int fst = q[x][0];
            int scd = q[x][1];
            int thr = q[x][2];

            //dbg(fst); dbg(scd); dbg(thr);
            //dbg(act);
            if (seen_p[fst]+seen_p[scd]+seen_p[thr] == 2) {

                if (!seen_p[fst]) {
                    ans[idx++] = fst;
                    seen_p[fst] = 1;
                }
                if (!seen_p[scd]) {
                    ans[idx++] = scd;
                    seen_p[scd] = 1;
                }
                if (!seen_p[thr]) {
                    ans[idx++] = thr;
                    seen_p[thr] = 1;
                }
                seen_q[x] = 1;
                break;
            }
        }
        act++;
    }

    fr(i, n) cout << ans[i] << " "; 
    cout << endl;
}
