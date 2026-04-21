#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}
//扩展->欧基米得算法
int main(){
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b);
    return 0;
}

