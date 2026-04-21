#include <bits/stdc++.h>
using namespace std;
int b[10001];
int main(){
	long long a,s;
	cin >> a;
	for(int i = 1;i <= a;i++){
	    cin >> b[i];	
	}
	sort(b,b+a);
	return 0;
}
