// http://codeforces.com/problemset/problem/18/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define EPS 1e-4
#define f first
#define s second

const float PI = acos(-1);	

typedef long long int ll;
typedef pair<double,double> pii;
typedef vector<int> vi;

pii p[4];

double opa(pii x, pii y) 
{ 
    double xd = x.f - y.f; 
    double yd = x.s - y.s; 
    return xd*xd + yd*yd; 
} 

int coisa(){
	double a2 = opa(p[2], p[3]);
	double b2 = opa(p[1], p[3]);
	double c2 = opa(p[1], p[2]);

	double a = sqrt(a2);
	double b = sqrt(b2);
	double c = sqrt(c2);

	double ang1 = acos((b2 + c2 - a2)/(2*b*c));
	double ang2 = acos((a2 + c2 - b2)/(2*a*c));
	double ang3 = acos((a2 + b2 - c2)/(2*a*b));

	ang1 = ang1*180/PI;
	ang2 = ang2*180/PI;
	ang3 = ang3*180/PI;

	if (isnan(ang1)) return 1;
	if (isnan(ang2)) return 1;
	if (isnan(ang3)) return 1;

	//cout << abs(ang1 - 90.0) << endl;
	//cout << ang2 << endl;
	//cout << ang3 << endl;

	if (abs(ang1 - 90.0) < EPS) return 1;
	if (abs(ang2 - 90.0) < EPS) return 1;
	if (abs(ang3 - 90.0) < EPS) return 1;

	return 0;
}

int main(){

	
	frr(i, 3){
		double x, y;
		cin >> x >> y;
		p[i] = {x,y};
	}

	fr(i, 4){

		p[i].f++;
		if(coisa()){
			if (i == 0) printf("RIGHT\n");
			else printf("ALMOST\n");
			return 0;
		}
		p[i].f--;

		p[i].s++;
		if(coisa()){
			if (i == 0) printf("RIGHT\n");
			else printf("ALMOST\n");
			return 0;
		}
		p[i].s--;
	}

	cout << "NEITHER" << endl;
}