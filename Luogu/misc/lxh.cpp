#include <bits/stdc++.h>
using namespace std;

void myswap(int* m,int* n){
	int t = *m;
	*m = *n;
	*n = t;
}

int main(){
	
	int a = 2,b = 3;
	myswap(&a,&b);
	cout << a << " " << b << endl;
	
	return 0;
	}
    
/*
    int a;
898852647
*/
