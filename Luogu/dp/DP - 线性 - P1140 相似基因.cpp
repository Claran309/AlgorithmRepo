#include <bits/stdc++.h>
using namespace std;
int na,nb,a[1001],b[1001],dp[1001][1001];
char in;
int d[6][6] = 
   {{0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}}; 
	
int main(){
	cin >>na;
	for(int i = 1;i <= na;i++){
		cin >> in;
		if(in == 'A') a[i] = 1;
		if(in == 'C') a[i] = 2;
		if(in == 'G') a[i] = 3;
		if(in == 'T') a[i] = 4;
	}
	cin >>nb;
	for(int i = 1;i <= nb;i++){
		cin >> in;
		if(in == 'A') b[i] = 1;
		if(in == 'C') b[i] = 2;
		if(in == 'G') b[i] = 3;
		if(in == 'T') b[i] = 4;
	}
	for(int i = 1;i <= na;i++) dp[i][0] = dp[i-1][0]+d[a[i]][5];
	for(int i = 1;i <= nb;i++) dp[0][i] = dp[0][i-1]+d[5][b[i]];
	for(int i = 1;i <= na;i++)
		for(int j = 1;j <= nb;j++)
			dp[i][j] = max(dp[i-1][j-1]+d[a[i]][b[j]],max(dp[i-1][j]+d[a[i]][5],dp[i][j-1]+d[5][b[j]]));
	cout << dp[na][nb];
	return 0;
}
