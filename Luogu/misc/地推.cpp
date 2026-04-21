#include <bits/stdc++.h>
using namespace std;
int n;
int f(int s){
	if(s <= 4) return s;
	return f(s-1)+f(s-3);
}
int main(){
	cin >> n;
	cout << f(n);
	return 0;
}
