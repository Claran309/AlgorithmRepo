#include <iostream>
#include <algorithm>
using namespace std;
int judge(int n) {
	int h = 1;
	while (n / 2) {
		h *= 2;
		n /= 2;
	}
	return h;
}
int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	while (n) {
		cout << judge(n) << " ";
		n -= judge(n);
	}
	return 0;
}
