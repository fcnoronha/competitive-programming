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

bool freq[12];
int cnt;
ll k, n, aux;

int main(){
    fastio

    while (cin>>n) {
        ms(freq,0);
        cnt = 10;
        k = 0;

        while(cnt>0){
            k++;
            aux = k*n;

            while (aux > 0){
                if(freq[aux%10]==0){
                    freq[aux%10]=1;
                    cnt--;
                }
                aux /=10;
            }
        }
        cout<<k<<endl;

    }
}
