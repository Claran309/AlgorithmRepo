#include <bits/stdc++.h>
using namespace std;
struct tree{
	int w,l,r;
} t[13000];
int ans,f,ans1,ans2,tc,com[13000],temp[13000],c,n,last[13000];
int main(){
	cin >> n;
	n = pow(2,n);
	c = n;
	for(int i = 1;i <= n;i++){
		cin >> last[i];
		com[i] = last[i];
	}
	if(n == 2){
		cout << max(last[1],last[2]);
		return 0;
	}
	while(n != 2){//跳出循环时为决胜状态 
		tc = 1;
		for(int i = 1;i <= n;i++){
			if(i%2==0){//合成树 
				int p = max(com[i],com[i-1]);//com比较,temp暂存,坐标为了防止重复做+n处理 
				t[p+n/2].w = p;//存节点 
				if(n == 4 && f == 0){
					ans1 = p;f = 1;
				}else if(n == 4 && f == 1) ans2 = p;//存答案 (决胜局)
				temp[tc++] = p;//暂存结果 
				t[com[i-1]+n].w = com[i-1];//存左节点 
				t[com[i]+n].w = com[i];//存右节点 
				t[p+n/2].l = com[i-1]+n;//存左节点坐标 
				t[p+n/2].r = com[i]+n;//存右节点坐标 
			}
		}
		memset(com,0,sizeof(com));
		for(int i = 1;i <= tc;i++)
			com[i] = temp[i];
		memset(temp,0,sizeof(temp));//转存com用于下一次合成树 
		n/=2;//数量缩小一倍 
	}
	ans = min(ans1,ans2);
	for(int i = 1;i <= c;i++)
		if(last[i] == ans)
			cout << i;
	return 0;
}
