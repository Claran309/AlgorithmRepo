#include <bits/stdc++.h>// 0 代表这一步走白 || 1 这一步走黑 || 用color标记 
using namespace std;
int p1[4][4],p2[4][4],sx1,sy1,sx2,sy2,dx[4] = {0,0,-1,1},dy[4] = {1,-1,0,0};
bool f;
char m[4][4];
//int ida();
void iddfs(int x1,int y1,int x2,int y2,bool color,int k,int temp);
int main(){
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++){
			cin >> m[i][j];
			if(m[i][j] == 'O' && f == false){
				sx1 = i,sy1 = j;// 存储 空白一 
				f = true;
			}else if(m[i][j] == 'O' && f == true) sx2 = i,sy2 = j;// 存储 空白二 
		}
	f = false;
	
//	system("CLS");
	
	for(int i = 0;i <= INT_MAX;i++){
		iddfs(sx1,sy1,sx2,sy2,0,0,i);// 白子先手 
		iddfs(sx1,sy1,sx2,sy2,1,0,i);// 黑子先手 
		if(f == true){
			cout << i;// 找到结果 
			return 0;
		}
	}
}
void iddfs(int x1,int y1,int x2,int y2,bool color,int k,int temp){
	
//	Sleep(1);
//	system("CLS");
//	for(int i = 0;i < 4;i++){
///		for(int j = 0;j < 4;j++)
//			cout << m[i][j];
//		cout << endl;
//	}
//	printf("k = %d   temp = %d   color = %d\n",k,temp,color);
	
	//if(ida()-1 + k > temp) return; // 启发式
	if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 >= 4 || y1 >= 4 || x2 >= 4 || y2 >= 4) return; // 边界
	if(k == temp){ // 找到尽头 
		//if(!ida()) f = true;// 满足条件 
		if(m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[2][2] == m[3][3]) f = true;// 右斜
		if(m[0][3] == m[1][2] && m[1][2] == m[2][1] && m[2][1] == m[3][0]) f = true;// 左斜 
		if(m[0][0] == m[1][0] && m[1][0] == m[2][0] && m[2][0] == m[3][0]) f = true;
		if(m[0][1] == m[1][1] && m[1][1] == m[2][1] && m[2][1] == m[3][1]) f = true;
		if(m[0][2] == m[1][2] && m[1][2] == m[2][2] && m[2][2] == m[3][2]) f = true;
		if(m[0][3] == m[1][3] && m[1][3] == m[2][3] && m[2][3] == m[3][3]) f = true;//
		if(m[0][0] == m[0][1] && m[0][1] == m[0][2] && m[0][2] == m[0][3]) f = true;
		if(m[1][0] == m[1][1] && m[1][1] == m[1][2] && m[1][2] == m[1][3]) f = true;
		if(m[2][0] == m[2][1] && m[2][1] == m[2][2] && m[2][2] == m[2][3]) f = true;
		if(m[3][0] == m[3][1] && m[3][1] == m[3][2] && m[3][2] == m[3][3]) f = true;
		return;
	} 
	for(int i = 0;i < 4;i++){// 考虑 白子黑子交替下 和 双空白 的搜索 
		int xx1 = x1 + dx[i],yy1 = y1 + dy[i],xx2 = x2 + dx[i],yy2 = y2 + dy[i];
		if(m[xx1][yy1] == 'B' && color == 1 && !p1[xx1][yy1]){// 空白一 走黑子 
			p1[xx1][yy1] = 1;
			swap(m[x1][y1],m[xx1][yy1]);
			iddfs(xx1,yy1,x2,y2,!color,k+1,temp);
			p1[xx1][yy1] = 0;
			swap(m[x1][y1],m[xx1][yy1]);
		}
		if(m[xx2][yy2] == 'B' && color == 1 && !p2[xx2][yy2]){// 空白二 走黑子 
			p2[xx2][yy2] = 1;
			swap(m[x2][y2],m[xx2][yy2]);
			iddfs(x1,y1,xx2,yy2,!color,k+1,temp);
			p2[xx2][yy2] = 0;
			swap(m[x2][y2],m[xx2][yy2]);
		}
		if(m[xx1][yy1] == 'W' && color == 0 && !p1[xx1][yy1]){//空白一 走白子 
			p1[xx1][yy1] = 1;
			swap(m[x1][y1],m[xx1][yy1]);
			iddfs(xx1,yy1,x2,y2,!color,k+1,temp);
			p1[xx1][yy1] = 0;
			swap(m[x1][y1],m[xx1][yy1]);
		}
		if(m[xx2][yy2] == 'W' && color == 0 && !p2[xx2][yy2]){//空白二 走白子 
			p2[xx2][yy2] = 1;
			swap(m[x2][y2],m[xx2][yy2]);
			iddfs(x1,y1,xx2,yy2,!color,k+1,temp);
			p2[xx2][yy2] = 0;
			swap(m[x2][y2],m[xx2][yy2]);
		}
	} 
}
/*
int ida(){// 调试
	int sum = INT_MAX;
	for(int i = 0;i < 4;i++){
		for(int j = 1;j < 4;j++)// 竖线四子 
			if(m[i][j] != m[i][j-1]){
				sum = min(sum,4-j);
				break;
			}
		if(i == 0){// 右斜四子 
			i = 1;
			for(int j = 1;j < 4;j++,i++)
				if(m[i][j] != m[i-1][j-1]){
					sum = min(sum,4-j);
					break;
				}
			i = 0;
		}else if(i == 3){// 左斜四子 
			i = 2;
			for(int j = 1;j < 4;j++,i--)
				if(m[i][j] != m[i+1][j-1]){
					sum = min(sum,4-j);
					break;
				}
			i = 3;
		}	
	}
	for(int i = 0;i < 4;i++)// 横线四子 
		for(int j = 1;j < 4;j++)
			if(m[j][i] != m[j-1][i]){
				sum = min(sum,4-j);
				break;
			}
	if(sum == INT_MAX) sum = 0;// 达成结束条件 
	return sum;
}*/
