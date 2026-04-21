/*
思路：
1.每次找最小边 ---- G:cmp&sort
2.判断当前边是否会树内互连 ---- G:并查集 
3.否，即为当前答案+1，继续下一循环；是，舍弃，进入下一循环  ---- G:并查集 
*/ 
#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to,w,fr;
} d[100001]; 
int n,m,cv,cu,cw,father[100001],ans;
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int find(int x){
	if(father[x] != x) father[x] = find(father[x]);
	return father[x];
}
void unionn(int x,int y){
	father[y] = x;
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) father[i] = i;//并查集 
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu >> cw;
		d[i].fr = cv,d[i].to = cu,d[i].w = cw;//存边 
	}
	sort(d+1,d+m+1,cmp);//以边的权值排序，升序 
	for(int i = 1;i <= m;i++){
		int r1 = find(d[i].fr),r2 = find(d[i].to);//是否在同一棵树上 
		if(r1 != r2){
			ans += d[i].w;//否，更新 
			unionn(r1,r2);
		}
	}
	cout << ans;
	return 0;
}
/*
4 6
1 2 4
1 3 9
1 4 21
2 3 8
2 4 17
3 4 16

28




#include <bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,w;
};
int father[101],n,maps[101][101],x,y,cnt,ans;
edge d[10001];
bool cmp(edge x,edge y);
int find(int x);
void unionn(int r1,int r2);
int main(){
	cin >> n;
	cnt++;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			cin >> maps[i][j];
			if(maps[i][j] != 0){
				d[cnt].from = i;d[cnt].to = j;d[cnt].w = maps[i][j];
				cnt++;
			}
		}
	sort(d+1,d+cnt,cmp);
	for(int i = 1;i <= n;i++) father[i] = i;
	for(int i = 1;i <= cnt-1;i++){
		int r1 = find(d[i].from),r2 = find(d[i].to);
		if(r1 != r2) {
			unionn(r1,r2);
			ans+=d[i].w;
		}
	}
	cout << ans;
	return 0;
}
int find(int x){
	if(father[x] != x) father[x] = find(father[x]);
	return father[x];
}
void unionn(int r1,int r2){
	father[r2] = r1;
}
bool cmp(edge x,edge y){
	return x.w < y.w;
}
*/
