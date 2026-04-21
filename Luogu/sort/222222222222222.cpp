#include <bits/stdc++.h>
using namespace std;
int p[100];
int main(){
	int b,l;
	cin >> b;
	int c[b];
	for(int i = 0;i < b;i++) cin >> c[i]; 
	sort(c,c+b);
	for(int i = 0;i < b;i++){
		if(c[i] == c[i-1]){
			continue;
		}
		p[i] = c[i];
		l++;
	}
	sort(p,p+l);
	cout << l << endl;
	for(int i =0;i<b;i++){
		if(p[i] != 0){
			cout << p[i] << " ";
		}
	}
	return 0;
} 
/**/
