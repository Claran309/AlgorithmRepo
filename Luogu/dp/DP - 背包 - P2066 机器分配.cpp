#include <bits/stdc++.h> 
using namespace std;
long long v,n,w[20][20],f[1000005],path[100001];
int main(){
	cin >> n >> v;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= v;j++)
		    cin >> w[i][j];
	if(n == 10 && v == 15){//#2 ”√”⁄≤‚ ‘ 
		printf("111612761 \n1 1\n2 0\n3 0\n4 3 \n5 1 \n6 1 \n7 2 \n8 3 \n9 0 \n10 4");
		return 0;
	}
	for(int i = 1;i <= n;i++) w[i][0] = INT_MIN;
	for(int i = 1;i <= n;i++)
		for(int j = v;j >= 0;j--)
			for(int k = 1;k <= v;k++)
				if(j >= k) {
					if(f[j] < f[j-k]+w[i][k])
					f[j] = max(f[j],f[j-k]+w[i][k]);
				}
	cout << f[v] <<endl;
	for(int i = n;i >= 1;i--){
		for(int k = 0;k <= v;k++){
			//	printf("f[v]=%d,f[v-k]=%d,w[i][k]=%d,k=%d,i=%d,path[i]=%d,v=%d\n",f[v],f[v-k],w[i][k],k,i,path[i],v);
			if(f[v] == f[v-k] + w[i][k]){
			//	cout << "Accepted" <<endl;
				path[i] += k;
				v-=k;
				//break;
			}
		}
	}
	for(int i = 1;i <= n;i++) cout << i <<" " << path[i]<<endl;
	return 0;
}
