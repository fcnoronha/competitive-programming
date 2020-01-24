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

int n, t;
int b[20], dist[3700];

void bfs(){    
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        fr(i, n){ 
            int val = cur + b[i];
            val = max(val, 0);
            val = min(val, 3600);
            if(dist[cur] + 1 < dist[val]){
                dist[val] = dist[cur] + 1;
                q.push(val);
            }
        }
    }
}


int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &t);
        fr(i, n) scanf("%d", &b[i]);
        ms(dist, INF);
        bfs();
        for(int i = t; i <= 3600; i++){
            if(dist[i] != INF){
                printf("%d %d\n", dist[i], i - t);
                break;
            }
        }
    }
}