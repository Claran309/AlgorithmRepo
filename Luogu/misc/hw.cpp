#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,c;
	cin >> a;
	int b[a];
	for(int i = 0;i < a;i++) cin >> b[a];
	for(int i = 0;i < a-1;i++) 
	for(int j = 0;j < a-1-i;j++)
	if(b[j] > b[j+1]) {swap(b[j],b[j+1]); c++;}
	for(int i = 0;i < a;i++) cout << b[i] << " ";
	cout << endl;
	cout << c;
	return 0;
}
