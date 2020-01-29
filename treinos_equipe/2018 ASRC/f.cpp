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

bool is_op(char c) {

    string oi = "+-*/%";
    for (auto x: oi) if (x == c) return 1;
    return 0;
}

int main(){
    fastio;
    
    string s;
    getline(cin, s);

    string auxx;
    for (auto x: s) if (x != ' ') auxx+=x;

    s = auxx;

    string err;
    for (auto c: s) 
        if (c != '(' && c != ')') err += c;
    
    if (is_op(err[0]) || is_op(err[err.size()-1])) {
        p("error");
        return 0;
    }
    fr(i, err.size()-1) {

        if (err[i] >= 'a' && err[i] <= 'z' &&
            err[i+1] >= 'a' && err[i+1] <= 'z') {
                p("error");
                return 0;
            }
        if (is_op(err[i]) && is_op(err[i+1])) {
            p("error");
            return 0;
        }
    }

    while (1) {

        // base
        if (s.size() == 1) {
            if (s[0] >= 'a' && s[0] <= 'z') {
                p("proper");
                return 0;
            }
        }
        if (s.size() == 3) {
            if (s[0] >= 'a' && s[0] <= 'z'
             && s[2] >= 'a' && s[2] <= 'z'
             && is_op(s[1])) {
                 p("proper");
                 return 0;
             }
        }
        if (s.size() == 5) {
            if (s[1] >= 'a' && s[1] <= 'z'
             && s[3] >= 'a' && s[3] <= 'z'
             && is_op(s[2])
             && s[0] == '(' && s[4] == ')') {
                 p("improper");
                 return 0;
             }
        }

        // parenteses
        int cp = 0;
        for (auto c: s) {
            if (c == '(') cp++;
            else if (c == ')') {
                cp--;
                if (cp < 0) {
                    p("error");
                    return 0;
                }
            }
        }
        if (cp) {
            p("error");
            return 0;
        }

        // operator error
        for (int i = 0; i < s.size()-1; i++) {
            if (is_op(s[i]) && s[i+1] == ')') {
                p("error");
                return 0;
            }
            if (is_op(s[i]) && is_op(s[i+1])) {
                p("error");
                return 0;
            }
            if (s[i] == '(' && is_op(s[i+1])) {
                p("error");
                return 0;
            }
        }
        if (is_op(s[0]) || is_op(s[s.size()-1])) {
            p("error");
            return 0;
        }

        // () case
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == '(' && s[i+1] == ')') {
                p("error");
                return 0;
            }
        }

        // char error
        for (int i = 0; i < s.size()-1; i++)
            if (s[i] >= 'a' && s[i] <= 'z'
             && s[i+1] >= 'a' && s[i+1] <= 'z') {
                 p("error");
                 return 0;
             }

        // parent improper
        for (int i = 0; i < (int)s.size()-2; i++) {
            if (s[i] == '(' && s[i+2] == ')') {
                p("improper");
                return 0;
            }
        }
        
        // operator impŕoepr
        for (int i = 0; i < (int)s.size()-2; i++) {
            if (is_op(s[i]) && is_op(s[i+2]) && 
                s[i+1] >= 'a' && s[i+1] <= 'z') {
                p("improper");
                return 0;
            }
        }

        // reduce bitches
        string aux;
        fr(i, s.size()) {

            if (s[i] == ')' && i >= 4) {

                fr(j, i-4) aux += s[j];
                aux += 'a';
                for (int j = i+1; j < s.size(); j++) aux += s[j];

                break;
            }
        }

        s = aux;
    }
}
