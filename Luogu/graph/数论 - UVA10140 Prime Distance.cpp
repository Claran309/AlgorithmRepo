#include <bits/stdc++.h>
using namespace std;
struct point{
	int x,y,derta;
} maxp,minp;
int l,r;
bool prim[10000001];
bool num[10000001];
long long prime[10000001],n;//prime[0]´æ¸öÊý 
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
	int f = 1;
	while(scanf("%d%d",&l,&r) != EOF){
		if(f == 1) f = 2;
		else cout << endl;
		maxp.derta = 0,maxp.x = 0,maxp.y = 0,minp.derta = 0,minp.x = 0,minp.y = 0;
		memset(prim,true,sizeof(prim));
		memset(prime,0,sizeof(prime));
		eu_prime(sqrt(r));
		for(int i = 1;i <= prime[0];i++){
			for(int j = (floor)(l/prime[i])*prime[i];j <= r;j+=prime[i])
				if(j != prime[i]) prim[j] = false;
		}
		prim[0] = prim[1] = false;
		memset(prime,0,sizeof(prime));
		for(int i = l;i <= r;i++)
			if(prim[i] == true) prime[++prime[0]] = i;
		if(prime[0] <= 1){
			cout << "There are no adjacent primes.";
			continue;
		}
		minp.derta = 1e9;
		for(int i = 2;i <= prime[0];i++){
			if(prime[i]-prime[i-1] > maxp.derta) maxp.derta = prime[i]-prime[i-1],maxp.x = prime[i-1],maxp.y = prime[i];
			if(prime[i]-prime[i-1] < minp.derta) minp.derta = prime[i]-prime[i-1],minp.x = prime[i-1],minp.y = prime[i];
		}
		printf("%d,%d are closest, %d,%d are most distant.",minp.x,minp.y,maxp.x,maxp.y);
	}
	return 0;
} 
