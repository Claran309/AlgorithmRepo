#include <bits/stdc++.h>
using namespace std;

int num(int x){
	if(x == 5) return 10;
	return num(x + 1) + 2;
}

int main(){
	cout << num(1);
	return 0;
}
