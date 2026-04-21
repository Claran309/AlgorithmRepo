#include <bits/stdc++.h>
using namespace std;
int dp[8001][8001],n;
char s[8001];
bool check(int l,int r){//o(len/2) if l == r
	if((l+r)%2 == 0) return 0;//r+l-i
	for(int i = l;i <= (r+l)/2;i++){ 
		int j = r+l-i;
		if(s[i] != s[j]) return 0;
	} 
	return 1;
}
bool check2(int l,int r){ 
	for(int k = l+1;k <= r-1;k++) 
		if(check(l,k) && check(k+1,r)) return 1;
	return 0;
}
bool checks(int n){
	for(int i = 1;i <= n-1;i++)
		if(s[i] != s[i+1]) return 0;
	return 1;
}
int main(){
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	cin >> n;
	scanf("%s",s+1);
	int ans = 0;
	for(int i = 1;i <= n-1;i++)
		if(s[i] == s[i+1]) dp[i][i+1] = 1;
	for(int len = 3;len <= n;len++)
		for(int i = 1;i <= n-len+1;i++){
			int j = i+len-1;
			for(int k = i+1;k < i+len-1;k++){
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]);
				}
			if(s[i] == s[j]){
				if(check(i,j))
					dp[i][j]++;
			}else if(check2(i,j))
				dp[i][j]++;
			printf("%d 到 %d ---> 最多有%d个可目标子串\n",i,j,dp[i][j]);
		}
	//for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
	//		cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << dp[1][n];
	return 0;
}
/*
8
accabccb

5
*/
