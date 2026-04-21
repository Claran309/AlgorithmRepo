#include<iostream>
using namespace std;
int x, p, m, result;
int main(){
	cin >> x >> p >> m;
	result = 1;
	while ( p > 0 ){
		if (p % 2 == 1)
			result = result * x;
		p /= 2;
		x = (x * x) % m;
	}
	cout << result << endl;
	return 0;
}
