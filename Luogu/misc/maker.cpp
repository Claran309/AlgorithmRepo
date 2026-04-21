#include <bits/stdc++.h>
using namespace std;
int random(int n){
	return (long long)rand()*rand()%n;
}
int main(){
	srand((unsigned)time(0));
	int a = random(10);
	int b = random(10);
	cout << a << " " << b;
	return 0;
}
