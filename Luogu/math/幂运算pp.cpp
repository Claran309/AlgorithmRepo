#include <bits/stdc++.h>
using namespace std;

int npow(int a,int n){
	int ans = 1;
	while(n){
		if(n % 2 == 1){
			ans = ans * a;
		}
		a = a * a;
		n = n / 2; 
	}
	return ans;
}

int main(){
	cout << npow(3,60000000000);
	return 0;
}
