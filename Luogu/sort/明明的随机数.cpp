#include <bits/stdc++.h>
using namespace std;
bool a[1001] = {0};
int main(){
	int b,x;
	cin >> b;
	for(int i = 0;i < b;i++){ cin >> x; a[x] = true;}
	int cnt = 0;
	for(int i = 0;i < 1001;i++) 
	    if(a[i] == true) cnt++;
	cout << cnt << endl;
	for(int i = 0;i < 1001;i++) 
	    if(a[i] == true) cout << i << " ";
	return 0;
}
