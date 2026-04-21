//选手 GD-S***** 成功提交题目 struct。
//./GD-Senior/answers/GD-S*****/struct/struct.cpp size = 1628
 
    /*
17:30
这是大模拟吗？这是大模拟吗？这是大模拟吗？
还有一小时 可以随便做。
我来定义一棵树
用什么起名呢
就用我老婆吧（
就叫做 NoaTree! 
生盐诺亚我好喜欢你你快保佑我 1 小时写完大模拟
o ne ga i shi ma su 
 
 
Update On 17:56
这玩意真的写不动！！
暴力也打不动
算了去写 T4 
go men 我写不出来了 noa老婆对不起对不起对不起 
 
Update On 18:12
我超我 T2 对拍出锅了！完了完了
 
Update On 18:17
fixed. 
 
Update On 18:23
我想在 7 分钟内骗 5 分
 
Update On 18:27
muri desu  
*/
#include<bits/stdc++.h>
using namespace std;
int n, k;
struct MisonoMika{ //未花树存储结构体 
	int siz; //大小
	int modd; //对齐方式
	int n; //儿子节点数量
	int son[105]; //儿子节点编号 
	string nam[105];
} st[2005];
struct NoaTree{ //诺亚树存储地址 
	int son[105]; //儿子节点编号
	int s[105]; //儿节点大小的前缀和
	int n; //儿子节点数量
	int typ; //自己的类型
	string name; //自己的名字 
} tr[2005];
map<string, int> id; //对每个名字存下自己的编号
int rt = 1;
int tot = 0, tot1 = 0;
int insertSonMika(string typ, string nm){
	cin >> typ >> nm;
	int Id = id[typ];
	st[tot1].n ++;
	st[tot1].son[st[tot1].n];
	
	return 1;
}
int DefineStruct(){
	string nam;
	int k;
	cin >> nam >> k;
	tot1 ++;
	id[nam] = tot1;
	int modd = 0;
	string typ[105], nm[105];
	for(int i = 1; i <= k; i ++){
		cin >> typ[i] >> nm[i];
		int Id = id[typ[i]];
		int x = st[Id].modd;
		modd = min(modd, x);
	}
	return 0;
} 
int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	id["short"] = 2;
	id["byte"] = 1;
	id["int"] = 3;
	id["long"] = 4;
	st[1].n = 0, st[1].siz = 1, st[1].modd = 1;
	st[2].n = 0, st[2].siz = 2, st[2].modd = 2;
	st[3].n = 0, st[3].siz = 4, st[3].modd = 4;
	st[4].n = 0, st[4].siz = 8, st[4].modd = 8; 
	//我不管了
	//我认为全是ERR
	//我认为全是ERR！！ 
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cout << "It's Too Hard To Solve The Problem";
	}
	return 0;
} 
 
