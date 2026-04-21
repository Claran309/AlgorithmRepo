#include <bits/stdc++.h>//1. ±©Á¦ 2.Ç°×ººÍ 
using namespace std; 
int n,m,ma[1001][1001],x,y,ex,ey;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> x >> y >> ex >> ey;
		for(int i = x;i <= ex;i++)
			for(int j = y;j <= ey;j++) ma[i][j]++;
		//for(int i = 1;i <= n;i++){
		//for(int j = 1;j <= n;j++) cout << ma[i][j] << " ";
		//cout << endl;
	//}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) cout << ma[i][j] << " ";
		cout << endl;
	}
	return 0;
}
