#include <bits/stdc++.h>
using namespace std;
bool num[10001];
int prime[10001],n;//prime[0]´æ¸öÊý 
void eu_prime(int n){
	memset(num,true,sizeof(num));	
	prime[0] = 0;
	for(int i = 2;i <= n;i++){
		if(num[i]) prime[++prime[0]] = i;
		int j = 1;
		for(int j = 1;j <= prime[0] && i*prime[j] <= n;j++) { 
			num[i*prime[j]] = false;
			if(i%prime[j] == 0) break;
		} 
	}
}
int main(){
	cin >> n;
	eu_prime(n);
	cout << prime[0] << endl;
	for(int i = 1;i <= prime[0];i++){
		cout << prime[i] << " ";
	}
	return 0;
}
