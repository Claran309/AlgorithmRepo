#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i = 0;i < a.length();i++){
    	a[i] = tolower(a[i]);
	}
	for(int i = 0;i < b.length();i++){
		b[i] = tolower(b[i]);
	}
	a = ' '+ a + ' ';
	b = ' '+ b + ' ';
	int p = b.find(a);
	if(p == -1){
		cout << "-1";
	}else{
	    int up = p,s = 0;
	    while(up!=-1){
	    	s++;
	    	up = b.find(a,up+1);
		}
		cout << s;
		cout << " " << p;	
	}
}
