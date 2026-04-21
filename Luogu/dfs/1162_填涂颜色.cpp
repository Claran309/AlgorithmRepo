#include <bits/stdc++.h>//av999a.com
using namespace std;
int n,ma[31][31],test[31][31];
int dx[5] = {0,0,0,-1,1} , dy[5] = {0,1,-1,0,0};
void dfs(int x,int y,int how){
	if(how == 1){
		if(test[x][y] == 1) return ;
		if(test[x][y] == 0){
			for(int i = 1;i <= 4;i++){
				int xx = dx[i] + x,yy = dy[i] + y;
				test[x][y] = 1;
				dfs(xx,yy,1);
				//ma[x][y] = 0;
			}
		}
	}else if(how == 2){
		if(test[x][y] == 1) return ;
		if(test[x][y] == 0){
			for(int i = 1;i <= 4;i++){
				int xx = dx[i] + x,yy = dy[i] + y;
				test[x][y] = 2;
				ma[x][y] = 2;
				dfs(xx,yy,2);
			}
		}
	}
}
int main(){
	memset(test,1,sizeof(test));
	memset(ma,1,sizeof(ma));
	cin >> n;
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= n;j++){
		cin >> ma[i][j];
		test[i][j] = ma[i][j];
	}
	dfs(1,1,1);
	for(int i = 1;i <= n;i++) dfs(n,i,1);
	for(int i = 1;i <= n;i++) dfs(i,n,1);
	for(int i = 1;i <= n;i++) dfs(1,i,1);
	for(int i = 1;i <= n;i++) dfs(i,1,1);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++) dfs(i,j,2);
	// -------------------------------------------------------
	//cout << endl << "ma = " << endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) cout << ma[i][j] << " ";
		cout << endl;
	}
	//cout << endl << "test = " << endl;
	//for(int i = 1;i <= n;i++){
	//	for(int j = 1;j <= n;j++) cout << test[i][j] << " ";
   	//    cout << endl;
	//}
	return 0;
} 
