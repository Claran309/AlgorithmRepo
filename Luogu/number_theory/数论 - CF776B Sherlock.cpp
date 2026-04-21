#include <bits/stdc++.h>
using namespace std;
int a[1000001],n,color;
int fac(int n){
    if(n == 2 || n == 0) return n;
    if(n == 1) return 0;
    for(int i = 2;i * i <= n;i++)
        if(n % i == 0) return 0;
    return n;
}
int main(){
	//4不是8的质因子 
	cin >> n;
	for(int i = 1;i <= n;i++){
		if(!fac(i+1)) a[i+1] = 2;
		else a[i+1] = 1;
	}
	if(n <= 2) cout << 1 << endl;
	else cout << 2 << endl;
	for(int i = 1;i <= n-1;i++)
		cout << a[i+1] << " ";
	cout << a[n+1]; 
	return 0; 
}
