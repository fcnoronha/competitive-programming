#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define all(x) x.begin(),x.end()
#define int long long int
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int INF = 0x3f3f3f3f;

signed main(){
    fastio;
    string s;
    cin >> s;
    int sacou = 0;
    int pontosA = 0;
    int pontosB = 0;
    int jogosA = 0;
    int jogosB = 0;
    int n = s.size();
    int acabou = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == 'Q'){
            if(acabou){
                cout << jogosA << " ";
                if(jogosA == 2) cout << "(winner)";
                cout << " - ";
                cout << jogosB << " ";
                if(jogosB == 2) cout << "(winner)";
                cout << endl;
            }
            else{
                cout << jogosA << " " << "(" << pontosA;
                if(sacou == 0) cout << "*";
                cout << ") - ";
                cout << jogosB << " (";
                cout << pontosB;
                if(sacou == 1) cout << "*";
                cout << ")";
                cout << endl;
            }

            continue;
        }
        if(acabou) continue;
        if(s[i] == 'S') {
            if(sacou == 0) pontosA++;
            else {
                sacou = 1;
                pontosB++; 
            }
        }
        else{
            if(sacou == 0) {
                pontosB++;
                sacou = 1;
            }
            else {
                pontosA++;
                sacou = 0;
            }

        }
        if(pontosA == 10 || (pontosA >= 5 && abs(pontosA-pontosB) >= 2) ){
            pontosA = 0;
            pontosB = 0;
            jogosA++;
            if(jogosA == 2) acabou = 1;
            }
        else if(pontosB == 10 || (pontosB >= 5 && abs(pontosA-pontosB) >= 2) ){
            pontosB = 0;
            pontosA = 0;
            jogosB++; 
            if (jogosB == 2) acabou = 1;         
        }
    }

    
}