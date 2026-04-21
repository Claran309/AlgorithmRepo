#include <bits/stdc++.h>//距离减半径最小的就是扩展范围     油滴被覆盖 
using namespace std;
int n,sx,sy,ex,ey,sum[7],p[7];
double out,ans;
struct oil{ 
	int ox; int oy; double r;
} pots[7],dpots[7]; 
double dis(int x1,int x2,int y1,int y2){ //计算圆心距
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
} 
void r(int x,int y,int step){//计算油滴能达到的最大半径 
	pots[step].r = min(min(abs(x-sx),abs(y-sy)),min(abs(ex-x),abs(ey-y)));
	for(int ii = step-1;ii >= 1;ii--){
		pots[step].r = min(pots[step].r,abs(dis(pots[step].ox,pots[ii].ox,pots[step].oy,pots[ii].oy)-pots[ii].r));
	}
	ans+=3.1415*pots[step].r*pots[step].r;
}
void dfs(int k){ //计算全排列 
	if(k > n){ 
		for(int i = 1;i <= n;i++){ 
			pots[i].ox = dpots[p[i]].ox;
			pots[i].oy = dpots[p[i]].oy;
			r(pots[i].ox,pots[i].oy,i);
		} //数据转移 
		out = max(out,ans);//取最大油滴覆盖面积 
		ans = 0;
	} 
	for(int i = 1;i <= n;i++)
		if(!sum[i]){ 
			sum[i] = 1;
			p[k] = i;
			dfs(k+1);
			sum[i] = 0;
		} 
} 
int main(){
	cin >> n >> sx >> sy >> ex >> ey;
	for(int i = 1;i <= n;i++){
		cin >> dpots[i].ox >> dpots[i].oy; 
	}
	dfs(1);
	if(int((abs(sx-ex)*abs(sy-ey) - out)*10)%10 >= 5) cout << ceil(abs(sx-ex)*abs(sy-ey) - out);//四舍五入 
	else cout << int(abs(sx-ex)*abs(sy-ey) - out);
	return 0;
}
/*
2
20 0 10 10
13 3
17 7
50
*/
