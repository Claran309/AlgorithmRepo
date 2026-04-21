#include <bits/stdc++.h>//我第一印象觉得是分组背包(价钱差>3的为一组),但是不对! 而且数据为10^9,要用进制优化？ 
//思路看了题解：    反思： 对于 [有依赖的背包]没有思路 --- 没看到数据范围不用考虑极差！？！？！？！？！？！？！？！？！ 
//不理解 : 该思路如何想到做到的令 极差<=3 ？??? 原来不用考虑极差？？？ 
//要考虑的就是01背包的优化
//优化前：
/*
#include <bits/stdc++.h>
using namespace std;
int n,v,c[100001],w[100001],f[100000001],ans;
int main(){
	cin >> n >> v;
	for(int i = 1;i <= n;i++)
		cin >> c[i] >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j = v;j >= c[i];j--){
			f[j] = max(f[j],f[j-c[i]]+w[i]);
			ans = max(ans,f[j]);
		}
	cout << ans;
	return 0;
}

*/ 
using namespace std;
int n,v,c[1001],w[1001],f[101][1000001],ans,minc,sc;
int main(){
	cin >> n >> v;
	minc = 1e8;
	for(int i = 1;i <= n;i++) {
		cin >> c[i] >> w[i];
		minc = min(minc,c[i]);
		sc += c[i];
	} 
	for(int i = 1;i <= n;i++) c[i] -= minc;
	sc -= n*minc;
	for(int i = 1;i <= n;i++)
		for(int j = sc;j >= c[i];j--)
			for(int k = n;k >= 1;k--)
				if(j+k*minc <= v) f[j][k] = max(f[j][k],f[j-c[i]][k-1]+w[i]);
	for(int i = 1;i <= sc;i++)
		for(int j = 1;j <= n;j++)
			ans = max(ans,f[i][j]);
	cout << ans;
	return 0;
} 

/* 以下为第一篇题解的思路↓(是我绝对想不到的) 
 
在预处理时将每个物品的体积都减去（MINV-1）
其中MINV是所以物品中的最小的体积（价值）
再在dp数组中多加一维，记录一共选了几个
这样做的目的是可以知道当前选的总体积
dp[i][j]表示我选的修改后的物品的体积为i，选了j个
则当前的总体积为：i+j*minv 
*/
