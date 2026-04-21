#include <bits/stdc++.h>
using namespace std;  	
char a[100001],b[100001];
int p[100001],pp[100001];
int main(){
	
	gets(a);
	gets(b);
	int w = max(strlen(a),strlen(b));
	for(int i = 0;i <= w;i++){
		
	    if((a[i]-'0')+(b[i]-'0') >= 10){
	    	p[i]-=10;
	    	++p[i+1];
		}
		p[i] = (a[i]- '0');
		pp[i] = (b[i] - '0');
	}
	return 0;
} 
