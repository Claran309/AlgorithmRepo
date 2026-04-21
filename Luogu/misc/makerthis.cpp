#include <bits/stdc++.h>
using namespace std;
long long random(int n){
	return (long long)rand()*rand()%n;
}
int main(){
	srand((unsigned)time(0));
	int t = random(10000)+1;
	int k = random(21)+1;
	cout << t << " " << k;
	for(int i = 1;i <= t;i++){
		int a = random(2000)+1,b = random(2000)+1;
		cout << " " << a << " " << b;
	}
	return 0;
}
