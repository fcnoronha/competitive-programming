#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define inf INT_MAX
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define mod 1000000009

int n,m,c;

char mpp[51][51];
int cost[51];

//cost, line, interval
vector<pair<int,pair<int,pii>>> intervals(int i){
    vector<pair<int,pair<int,pii>>> ans;
    for(int j=0;j<m;j++){
        int cst=0;
        for(int k=j;k<m;k++){
            if(mpp[i][k]=='.'||mpp[i][k]=='B')break;
            cst+=cost[mpp[i][k]-'a'];
            ans.pb(mp(cst,mp(i,mp(j,k))));
        }
    }
    return ans;
}

int lb,cb;

vector<pair<int,pair<int,pii>>> g1[51][51][51];
vector<pair<int,pair<int,pii>>> g2[51][51][51];

vector<pair<int,pair<int,pii>>> aa[51];

int dis1[51][51][51];
int dis2[51][51][51];

void dij(pair<int,pair<int,pii>> x){
    for(int i=0;i<31;i++){
        for(int j=0;j<31;j++){
            for(int k=0;k<31;k++){
                dis1[i][j][k]=dis2[i][j][k]=-1;
            }
        }
    }
    priority_queue<pair<int,pair<int,pii>>> q1;
    dis1[x.s.f][x.s.s.f][x.s.s.s]=x.f;q1.push(mp(-1*x.f,x.s));
    while(!q1.empty()){
        pair<int,pii> ax=q1.top().s;
        int c=-q1.top().f;
        q1.pop();
        auto &disx=dis1[ax.f][ax.s.f][ax.s.s];
        if(disx!=c)continue;
        for(auto at:g1[ax.f][ax.s.f][ax.s.s]){
            pair<int,pii> y=at.s;
            int c=at.f;
            auto &disy=dis1[y.f][y.s.f][y.s.s];
            if(disy==-1||disx+c<disy){
                disy=disx+c;
                q1.push(mp(-disy,y));
            }
        }
    }
    priority_queue<pair<int,pair<int,pii>>> q2;
    dis2[x.s.f][x.s.s.f][x.s.s.s]=x.f;q2.push(mp(-1*x.f,x.s));
    while(!q2.empty()){
        pair<int,pii> ax=q2.top().s;
        int c=-q2.top().f;
        q2.pop();
        auto &disx=dis2[ax.f][ax.s.f][ax.s.s];
        if(disx!=c)continue;
        for(auto at:g2[ax.f][ax.s.f][ax.s.s]){
            pair<int,pii> y=at.s;
            int c=at.f;
            auto &disy=dis2[y.f][y.s.f][y.s.s];
            if(disy==-1||disx+c<disy){
                disy=disx+c;
                q2.push(mp(-disy,y));
            }
        }
    }
}


int role(){
    for(int i=0;i<n;i++)aa[i]=intervals(i);
    /*for(int i=0;i<n;i++){
        for(auto x:aa[i]){
            cout<<x.f<<" "<<x.s.f<<" "<<x.s.s.f<<" "<<x.s.s.s<<endl;
        }
    }*/
    for(int i=0;i<lb;i++){
        for(auto &x:aa[i]){
            for(auto &y:aa[i+1]){
                int meno=min(x.s.s.f,y.s.s.f);
                int maio=max(x.s.s.s,y.s.s.s);
                if(maio-meno+1<=
                    x.s.s.s-x.s.s.f+y.s.s.s-y.s.s.f+2){
                    //cout<<"aresta 1"<<endl;
                    //cout<<x.f<<" "<<x.s.f<<" "<<x.s.s.f<<" "<<x.s.s.s<<endl;
                    //cout<<y.f<<" "<<y.s.f<<" "<<y.s.s.f<<" "<<y.s.s.s<<endl;
                    g1[x.s.f][x.s.s.f][x.s.s.s].pb(y);
                    g1[y.s.f][y.s.s.f][y.s.s.s].pb(x);
                }
            }
        }
    }
    for(int i=lb;i<n;i++){
        for(auto &x:aa[i]){
            for(auto &y:aa[i+1]){
                int meno=min(x.s.s.f,y.s.s.f);
                int maio=max(x.s.s.s,y.s.s.s);
                if(maio-meno+1<=
                    x.s.s.s-x.s.s.f+y.s.s.s-y.s.s.f+2){

                    //cout<<"aresta 2"<<endl;
                    //cout<<x.f<<" "<<x.s.f<<" "<<x.s.s.f<<" "<<x.s.s.s<<endl;
                    //cout<<y.f<<" "<<y.s.f<<" "<<y.s.s.f<<" "<<y.s.s.s<<endl;
                    g2[x.s.f][x.s.s.f][x.s.s.s].pb(y);
                    g2[y.s.f][y.s.s.f][y.s.s.s].pb(x);
                }
            }
        }
    }

    int resp=inf;
    for(auto &x:aa[lb]){
        if(x.s.s.s<cb){
            //cout<<"banana"<<endl;
            dij(x);
            for(auto &y:aa[lb]){
                if(y.s.s.f>cb){
                    int diss1=dis1[y.s.f][y.s.s.f][y.s.s.s];
                    int diss2=dis2[y.s.f][y.s.s.f][y.s.s.s];
                    if(diss1!=-1&&diss2!=-1){
                        resp=min(resp,
                            diss1+diss2-x.f-y.f);
                    }
                }
            }
        }
    }
    return resp;

}


int32_t main (){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>m>>n>>c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mpp[i][j];
            if(mpp[i][j]=='B'){
                lb=i;
                cb=j;
            }
        }
    }
    if(cb>m/2){
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                swap(mpp[i][j],mpp[i][m-j-1]);
            }
        }
        cb=m-cb-1;
    }
    for(int i=0;i<c;i++)cin>>cost[i];
    int resp=role();
    if(resp==inf)cout<<-1<<endl;
    else cout<<resp<<endl;

    return 0;
}
 