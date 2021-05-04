#include <bits/stdc++.h>
using namespace std;
     
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args);
#endif

#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int d[500], a[500], b[500], c[500];
int intersecta[3][3][500][500];
int chega[3][500][500];
int espera[3][500];

int n;
int calcula(int a, int b, int i, int j) {
    for (int k = 0; k<n; k++) {
        if (chega[a][i][k] + espera[a][k] > chega[b][j][k] && chega[b][j][k] + espera[b][k] > chega[a][i][k])
            return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> espera[0][i];
    }
    for (int i = 0; i<n; i++) {
        cin >> espera[1][i];
    }
    for (int i = 0; i<n; i++) {
        cin >> espera[2][i];
    }
    for (int z = 0; z<3; z++) {
        for (int i = 0; i<n; i++) {
            chega[z][i][i] = 0;
            int vv = i;
            while ( (vv+1)%n != i) {
                chega[z][i][(vv+1)%n] = chega[z][i][vv] + espera[z][vv] + d[vv]; 
                vv++;
                vv%=n;
            }
        }
    }

    for (int a = 0; a < 3; a++) {
        for (int b =0; b<3; b++) {
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    intersecta[a][b][i][j] = calcula(a,b,i,j);
                    
                }
            }
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<n; k++) {
                if (!intersecta[0][1][i][j] && !intersecta[0][2][i][k] && !intersecta[1][2][j][k]) {
                    cout << i+1 << " " << j+1 << " " << k+1 << endl;
                    exit(0);
                }
            }
        }
    }
    cout << "impossible" << endl;


}
 