#include <bits/stdc++.h>
using namespace std;
int main(){
	double a = 0;
	int f = 1;
	for(double i = 1;i <= 10000;i=i+2){
		a = a + 1/i*f;
		f = f*(-1);
	}
	cout << a*4;

	return 0;
}

/*

   »¬»ü


*/







