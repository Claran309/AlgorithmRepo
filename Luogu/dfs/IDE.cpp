#include <bits/stdc++.h>
#define maxn 10000000
using namespace std;
int depth = 1,use,t,s,a,b,ans[1001],d[1001];
bool found;
int gcd(int,int);
int num(int,int);
void dfs(int,int,int);
int main(){
	cin >> a >> b;
	use = gcd(a,b);
	a = a / use;
	b = b / use;
	if(a == 1){
		cout << b;
		return 0;
	}
	for( ; ;depth++){
		dfs(a,b,1);
		if(found){
			for(int i = 1;i <= depth;i++) cout << ans[i] << " ";
			break;
		}
	}
	return 0;
}
int gcd(int a,int b){
	int t = a % b;
	while(t){
		a = b;
		b = t;
		t = a % b;
	}
	return b;
}
void dfs(int a,int b,int k){
	if(k <= depth + 1) return ;
	else if(!(b % a)){
		d[k] == b/a;
		if(!found || d[k] < ans[k]) memcpy(ans,d,sizeof(d));
		found = true;
		return ;
	} 
	s = max(b/a,d[k-1])+1;
	t = (depth-k+1);
	t = min(t,maxn/b);
	for(int i = s;i <= t;i++){
		d[k] = i;
		a = a*i-b; b *= i;
		use = gcd(a,b);
		a = a / use; b = b / use;
		dfs(a,b,k+1);
	}
}
