#include <bits/stdc++.h>
using namespace std;
int n,m,ans = -233,ma[101][3],x,y,cnt;
int main(){
	cin >> n;
	x = 1;
	y = 1;
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= n;j++){
		cin >> cnt;
		ma[i][j] = ma[i-1][j] + ma[i][j-1] - ma[i-1][j-1] + cnt;
	}
	for(int i = 1;i + x - 1 <= n;i++){ 
		for(int j = 1;j + y - 1 <= n;j++){
			int ii = i + x - 1,jj = j + x - 1;
			cnt = ma[i-1][jj] + ma[ii][j-1] - ma[i-1][j-1];
			ans = max(ans,cnt);
		} 
		cout << ans;
	}	
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int n,m,ans = -233,ma[121][121],x,y,cnt;
int main(){ 
	cin >> n;
	x = n;
	y = 1;
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= n;j++){ 
		cin >> cnt;
		ma[i][j] = ma[i-1][j] + ma[i][j-1] - ma[i-1][j-1] + cnt;
	} 
	for(int i = 1;i + x - 1 <= n;i++){ 
		for(int j = 1;j + y - 1 <= n;j++){ 
			int ii = i + x - 1,jj = j + x - 1;
			cnt = ma[i-1][jj] + ma[ii][j-1] - ma[i-1][j-1];
			ans = max(ans,cnt);
		} 
		cout << ans;
	}	
	return 0;
}*/
