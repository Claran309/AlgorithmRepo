#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	getline(cin,a);
	int s = a.size();
	for(int i = s-1;i >= 0;i--){
		cout << a[i];
	}
	return 0;
}
