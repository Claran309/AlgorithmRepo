#include <bits/stdc++.h>
using namespace std;
struct input{
	int x,y;
} in[501];
struct edge{
	int from,to;
	double w;
} d[250000];
double m[501][501],ans[501];
int c,cnt,cv,cu,s,p,father[501];
int find(int x);
bool cmp(edge x,edge y);
bool cmp2(double x,double y);
void unionn(int r1,int r2);
double dis(int x1,int x2,int y1,int y2);
int main(){
	cin >> s >> p;
	for(int i = 1;i <= p;i++){
		cin >> cv >> cu;
		in[i].x = cv;in[i].y = cu;
	}
	for(int i = 1;i <= p;i++)
		for(int j = 1;j <= p;j++){
			if(i == j) continue;
			m[i][j] = dis(in[i].x,in[j].x,in[i].y,in[j].y);//构建完全图 
			if(j < i) continue;
			d[cnt].from = i; d[cnt].to = j; d[cnt].w = m[i][j];//存边 
			cnt++;
		}
	//接下来找最小生成树 
	for(int i = 1;i <= p;i++) father[i] = i;
	sort(d,d+cnt,cmp);
	for(int i = 0;i < cnt-1;i++){
		int r1 = find(d[i].from),r2 = find(d[i].to);
		if(r1 == r2) continue;
		unionn(r1,r2);
		ans[c] = d[i].w;//存最小生成树的边 
		c++;
	}
	sort(ans,ans+c,cmp2);
	printf("%.2lf",ans[s-1]);//删除s条最大的边后的结果 (即有p-(s-1)保留) 
	return 0;
} 
bool cmp(edge x,edge y){
	return x.w < y.w;
}
bool cmp2(double x,double y){
	return x > y;
}
double dis(int x1,int x2,int y1,int y2){
	return sqrt((double)(x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2));
}
int find(int x){
	if(father[x] != x) father[x] = find(father[x]);
	return father[x];
}
void unionn(int r1,int r2){
	father[r2] = r1;
}
