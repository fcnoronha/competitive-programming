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

struct pos{
    int a[3];
    bool operator == (pos other) const{
        fr(i, 3){
            if(a[i] != other.a[i]) return false;
        }
        return true;
    }
};

pos build(pos cur){
    pos plc;
    fr(i, 3) plc.a[i] = cur.a[i];
    return plc;
}

vector<pos> ans[2];
pos vaca[2];

int moves[3][2];

int sz[2];

bool movea(){
    pos nxt = build(ans[0][sz[0]]);
    bool moved = false;
    fr(i, 3){
        if(moves[i][0] == 0) continue;
        int dir = (moves[i][0] > 0)?1:-1;
        nxt.a[i] += dir;
        if(nxt == ans[1][sz[1]]){
            nxt.a[i] -= dir;
            continue;
        }
        moved = true;
        ans[0].pb(nxt);
        sz[0]++;
        moves[i][0] -= dir;
        break;
    }
    return moved;
}

bool moveb(){
    pos nxt = build(ans[1][sz[1]]);
    bool moved = false;
    fr(i, 3){
        if(moves[i][1] == 0) continue;
        int dir = (moves[i][1] > 0)?1:-1;
        nxt.a[i] += dir;
        if(nxt == ans[0][sz[0]]){
            nxt.a[i] -= dir;
            continue;
        }
        moved = true;
        ans[1].pb(nxt);
        sz[1]++;
        moves[i][1] -= dir;
        break;
    }
    return moved;
}

void forcemoveb(){
    pos nxt = build(ans[1][sz[1]]);
    fr(i, 3){
        if(moves[i][1] != 0) continue;
        nxt.a[i] += 1;
        if(!(nxt == ans[0][sz[0]])){
            ans[1].pb(nxt);
            sz[1]++;
            moves[i][1] = -1;
            break;
        } 
        nxt.a[i] -= 2;
        if(!(nxt == ans[0][sz[0]])){
            ans[1].pb(nxt);
            sz[1]++;
            moves[i][1] = 1;
            break;
        }
        nxt.a[i]++;
    }
}

void forcemovea(){
    pos nxt = build(ans[0][sz[0]]);
    fr(i, 3){
        if(moves[i][0] != 0) continue;
        nxt.a[i] += 1;
        if(!(nxt == ans[1][sz[1]])){
            ans[0].pb(nxt);
            sz[0]++;
            moves[i][0] = -1;
            break;
        } 
        nxt.a[i] -= 2;
        if(!(nxt == ans[1][sz[1]])){
            ans[0].pb(nxt);
            sz[0]++;
            moves[i][0] = 1;
            break;
        }
        nxt.a[i]++;
    }
}

int main(){
    fr(i, 2){
        pos plc;
        fr(j, 3) scanf("%d", &(plc.a[j]));
        fr(j, 3) scanf("%d", &(vaca[i].a[j]));
        ans[i].pb(plc);
        fr(j, 3){
            moves[j][i] = (plc.a[j]>vaca[i].a[j]?-1:1)*abs(plc.a[j] - vaca[i].a[j]);
        }
    }
    while(1){
        if(ans[0][sz[0]] == vaca[0] && ans[1][sz[1]] == vaca[1]){
            break;
        }
        if(ans[0][sz[0]] == vaca[0]){
            if(moveb()) {
                ans[0].pb(vaca[0]);
                sz[0]++;
                continue;
            }
            forcemovea();
            moveb();
        }
        else if(ans[1][sz[1]] == vaca[1]){
            if(movea()){
                ans[1].pb(vaca[1]);
                sz[1]++;
                continue;
            }
            forcemoveb();
            movea();
        }
        else{
            if(movea()){
                if(!moveb()) forcemoveb();
            }
            else if (moveb()){
                if(!movea()) forcemovea();
            }
            else forcemovea(), moveb();
        }
    }
    fr(i, sz[0]+1){
        printf("(%d %d %d) (%d %d %d)\n", ans[0][i].a[0], ans[0][i].a[1], ans[0][i].a[2], ans[1][i].a[0], ans[1][i].a[1], ans[1][i].a[2]);
    }
}
