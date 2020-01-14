//codeforces.com/contest/1283/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define all(x) x.begin(),x.end()
#define p(x) cout << x << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> vi;

int main(){
    fastio;

    int n;
    cin >> n;

    set<int> avlb;
    frr(i, n) avlb.insert(i);

    int f[n];
    fr(i, n) {
        cin >> f[i];

        if (f[i] != 0) avlb.erase(f[i]); 
    }

    vi aux;
    for (auto x: avlb) aux.pb(x);

    int fl[n];
    int ok;
    do {

        fr(i, n) fl[i] = f[i];

        shuffle(all(aux), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

        int idx = 0;
        fr(i, n) {

            if (fl[i]) continue;
            fl[i] = aux[idx++];
        }

        ok = 1;
        fr(i, n) if (fl[i] == i+1) ok = 0;

    } while (!ok);

    fr(i, n) cout << fl[i] << ' ';
    cout << endl; 
}
