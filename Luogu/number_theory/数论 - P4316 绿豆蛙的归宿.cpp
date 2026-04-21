#include <bits/stdc++.h>
using namespace std;
struct point{
	int to;
	double w;
};
double ans,p[100001];
int n,m,cu,cv,cw,rd[100001],cd[100001];
vector<point> v[100001];
queue<int> q;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cu >> cv >>cw;
		point in;in.to = cv;in.w = cw;
		v[cu].push_back(in);
		rd[cv]++;//入度++ 
		cd[cu]++;//出度++ 
	}
	for(int i = 1;i <= n;i++)
		if(rd[i] == 0) {
			q.push(i);
			p[i] = 1;//Topo找初始点 并将其概率设为 1 
		}
	while(!q.empty()){
		int out = q.front(),d = cd[q.front()];
		q.pop();
		double rp = p[out]/(double)d;//下一个点所能依靠此点分得的概率 
		for(int i = 0;i <= (int)v[out].size()-1;i++){
			ans += v[out][i].w*rp;//累加ans 
			p[v[out][i].to] += rp;//下一个点累加概率 
			rd[v[out][i].to]--;
			if(rd[v[out][i].to] == 0 && cd[v[out][i].to] != 0) q.push(v[out][i].to);//Topo 
		}
	}
	printf("%.2lf",ans);
	return 0;
}
