#include <bits/stdc++.h>
using namespace std;
int s(int* m,int* n){
	int t = *m;
	*m = *n;
	*n = t;
} 
int main(){
	int a = 2,b = 3;
	s(&a,&b);
	cout << a << " " << b << endl;
	
	
	
	return 0;
} 

