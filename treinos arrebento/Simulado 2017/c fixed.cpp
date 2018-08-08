#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

struct plate{
	int r;
	pair<int,int> pos;
};

vector<plate> table;
int q;

int find(pair<int,int> coord,int r){
	int tam;
	tam=table.size();
	if(tam==0)	return -1;		//se a lista easta vazia, entao nao tem o prato
	for(int i=0;i<tam;i++){
		if(coord==table[i].pos && r==table[i].r)	return i;	//se achou, retorna o indice do vetor correspondente ao prato
	}
	return -1;					//se a lista nao esta vazia e nao achei, entaoo nao tem
}

float distance(pair<int,int> a, pair<int,int> b){
	float x,y;
	x=a.first-b.first;
	y=a.second-b.second;
	return sqrt( x*x+y*y );
}

void remove(pair<int,int> pos,int r){
	int tam=table.size();
	int index=find(pos,r);
	if(index==-1){
		cout << "No" << endl;
		return;
	}

	cout << "Ok" << endl;
	table.erase(table.begin()+index);	
	return;
}

void insert(pair<int,int> coord, int r){
	int tam=table.size();
	plate obj;
	obj.pos=coord;
	obj.r=r;

	for(int i=0;i<tam;i++){
		if(distance(coord,table[i].pos)<r+table[i].r){
			cout << "No" << endl;
			return;
		}	
	}
	
	cout << "Ok" << endl;
	table.push_back(obj);
	
	return;
}

int main(){

	int r,x,y;
	char op;
	pair<int,int> coord;

	cin >> q;

	for(int i=0;i<q;i++){
		cin >> op >> x >> y >> r;
		coord=make_pair(x,y);
		if(op=='A')		insert(coord,r);
		if(op=='R')		remove(coord,r);
	}

	return 0;
}