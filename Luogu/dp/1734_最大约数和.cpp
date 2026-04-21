#include <bits/stdc++.h>
using namespace std;
int v[1001],S,dp[1001][1001];

int re_ans(int a){
	int ans;
	for(int i = 1;i < a;i++){
		if(a%i==0) ans+=i;
	}
	return ans;
}

int main(){
	cin >> S;
	for(int i = 1;i < S;i++){
		v[i] = re_ans(i);
	}
	for(int i = 1;i < S;i++)
		for(int j = 0;j <= S;j++)
			if(j < i) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j-i]+v[i],dp[i-1][j]);
	cout << dp[S-1][S];
	//-----------------------------------------------------------
	//for(int i = 0;i <= S;i++){
	//	for(int j = 0;j <= S;j++){
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	return 0;
}
