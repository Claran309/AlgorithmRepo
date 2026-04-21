#include <bits/stdc++.h>
using namespace std;

struct c{
	int num,scj,cj;
} f[1001];

int main(){
	int n;
	cin >> n;
	int a[1001];
	for(int i = 1;i <= n;i++) {
		cin >> f[i].num >> f[i].scj >> f[i].cj;
		a[i] = f[i].cj*70 + f[i].scj*30;
	}
	for(int i = 1;i <= n;i++)
	if(f[i].cj+f[i].scj > 140 && a[i] > 80){
			cout <<"Excellent" << endl;
		}else {
			cout <<  "Not Excellent" << endl;
		}
	
	return 0;
}
