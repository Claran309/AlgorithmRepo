#include <bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
} father[501][501];
char t[501];
int n,m,s[501],e[501];
point find(point x){
	if(father[x.x][x.y].x != x.x || father[x.x][x.y].y != x.y)//father[x.x][x.y].x/.y == x.x/.y
		father[x.x][x.y] = find(father[x.x][x.y]);
	return father[x.x][x.y];
}
void unionn(int r1x,int r1y,int r2x,int r2y){
	father[r2x][r2y].x = r1x;
	father[r2x][r2y].y = r1y;
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++) cin >> s[i] >> e[i] >> t[i];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++) father[i][j].x = i,father[i][j].y = j;
	for(int i = 1;i <= m;i++){
		point in1,in2;
		in1.x = s[i];in1.y = e[i];
		if(t[i] == 'R') in2.x = s[i],in2.y = e[i]+1;
		else if(t[i] == 'D') in2.x = s[i]+1,in2.y = e[i];
		point r1 = find(in1),r2 = find(in2);
		printf("´Ó(%d,%d)»­µ½(%d,%d)     %d   %d  |||   %d   %d\n",s[i],e[i],in2.x,in2.y,r1.x,r1.y,r2.x,r2.y);
		if(r1.x == r2.x && r1.y == r2.y){
			cout << i;
			return 0;
		}
		unionn(r1.x,r1.y,r2.x,r2.y);
	}
	cout << "draw";
	return 0;
} 
/*
3 5
1 1 D
1 1 R
1 2 D
2 1 R
2 2 D

4
*/
