#include <bits/stdc++.h>
using namespace std;


int main(){
	string frase,aux;
	int end,flag,letra;
  
 	getline(cin,frase); 
 	end = frase.size() - 1;
  
	if(frase[end]=='?'){
		cout << 7 << endl;
	    return 0;
	}
  
	int i=0;
  
	while(i+6<=end){
		aux="";
		
       	if(i==0){
    		for(int j=0;j<=5;j++){
				aux+=frase[i+j];
    		}
    	}
    	else{
    		for(int j=0;j<=6;j++){
				aux+=frase[i+j];
    		}
    	}
    	
    	if(aux=="Sussu " && i==0){
   			cout << "AI SUSSU!" << endl;
        	return 0;
        }		
    
   		else if(aux==" Sussu " || aux==" Sussu!" || aux==" Sussu." || aux==" Sussu," || aux==" Sussu;" && i<end-4){
   			cout << "AI SUSSU!" << endl;
        	return 0;
   		}
   		

   		if(aux==" Sussu" && i==end-4){
   			cout << "AI SUSSU!" << endl;
        	return 0;
   		}
   		
   		i++;     
    
  	}
  
 	cout << "O cara é bom!" << endl;
  
 	return 0;
  