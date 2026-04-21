#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];//存质数 true是质数 
void prim(int n){
	memset(prime,true,sizeof(prime));
	prime[1] = prime[0] = false;
	for(int i = 2;i*i <= n;i++){
		if(prime[i])
			for(int j = i*i;j <= n;j+=i)
				prime[j] = false;
	}
}
