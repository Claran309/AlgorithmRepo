#include <bits/stdc++.h>
using namespace std;
int a,b,ans[1001];
int gcd(int,int);
void rf(int,int);
void dfs(int,int,int);
int main(){
	cin >> a >> b;
	rf(a,b);
	if(a == 1){
		cout << b;
		return 0;
	}
	for(int depth = 1;1;depth++){
		dfs(a,b,1);
	}
	return 0;
}
int gcd(int a,int b){
	int t = a % b;
	while(t){
		a = b;
		b = t;
		t = a % b;
	}
	return b;
}
void rf(int& a,int& b){
	int use = gcd(a,b);
	a = a / use;
	b = b / use;
}
void dfs(int a,int b,int depth){
	
}
