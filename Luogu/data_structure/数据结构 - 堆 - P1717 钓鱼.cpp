//注释均为Claran(本人)手打 
#include <bits/stdc++.h>
using namespace std;
struct fish{
	int w,tmp;//存编号，之后减去数量要用 
};
bool operator < (fish x,fish y) {
	return x.w < y.w;//大根堆结构体排序 
}
int n,h,f[30],d[30],t[30],tsum,sum,cnt,ans;
int main(){
	scanf("%d%d",&n,&h);
	h = h*12;
	for(int i = 1;i <= n;i++)
		cin >> f[i];
	for(int i = 1;i <= n;i++)
		cin >> d[i];
	for(int i = 2;i <= n;i++)
		cin >> t[i];
	priority_queue<fish,vector<fish>,less<fish> > q;//大根堆 
	for(int end = 1;end <= n;end++){//枚举终点 
		tsum = h,sum = 0;
		while(!q.empty()) q.pop();//重置 
		for(int i = 1;i <= end;i++){//减时间&放入堆 
			tsum -= t[i];
			//cout << end << " " << tsum << endl;
			fish temp;temp.tmp = i;temp.w = f[i];
			q.push(temp);
		}
		while(tsum > 0){//尽量钓鱼 
			//cout << end << " " << tsum << " sum = " << sum << endl;
			tsum--;//减时间 
			sum += q.top().w;//加鱼 
			fish cnt;cnt.w = q.top().w-d[q.top().tmp],cnt.tmp = q.top().tmp;//减鱼 
			if(cnt.w < 0) cnt.w = 0;//防止减到负数 
			q.pop();//减鱼 
			q.push(cnt);//减鱼 
		}
		ans = max(ans,sum);//存最大值 
	}
	cout << ans;
	return 0;
}
