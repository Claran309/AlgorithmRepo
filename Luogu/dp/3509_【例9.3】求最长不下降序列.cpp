//¶¯Ì¬¹æ»® 
#include <iostream>
#include <algorithm>
using namespace std;
int dp[100000],a[100000],p[100000],n,ans;
int main(){ 
    cin >> n;
    for(int i = 1;i <= n ;i++) dp[i] = 1;
	for(int i = 1;i <= n ;i++) cin >> a[i];
	ans = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j < i;j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i],dp[j]+1);
				p[j] = i;
			}
		}
		ans = max(ans,dp[i]);
	}
	cout << "max=" << ans << endl;
	return 0;
} 
