#include <bits/stdc++.h>
using namespace std;
unsigned long long a;
int main(){
	cin >> a;
	if(a <= 1) cout << "No";
	else{
		for(int i = 2;i * i <= a;i++)
			if(a % i == 0){
				cout << "No";
				return 0;
			}
		cout << "Yes";
	}
	return 0;
}
