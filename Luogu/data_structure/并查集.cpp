#include <bits/stdc++.h>
using namespace std;
int father[200001];
int m,n,i,x,y,q;
int find(int x);
void unionn(int r1,int r2);
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) father[i] = i;//初始每个节点互相独立 
	for(int i = 1;i <= m;i++) {
		cin >> x >> y;
		int r1 = find(x),r2 = find(y);//寻找双方根节点 
		if(r1 != r2) unionn(r1,r2);//若根节点不同则合并 
	}
	cin >> q;
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		if(find(x) == find(y)) cout << "Yes" << endl;//根节点相同，属于一类 
		else cout << "No" << endl;
	}
	return 0;
} 
int find(int x){//寻找根节点 
	if(father[x] != x) father[x] = find(father[x]);//若根节点不是自己(即为其他节点的子树)则向上一级递归寻找根节点 
	return father[x];//真根节点 
}
void unionn(int r1,int r2){
	father[r2] = r1;//将r2接入r1 
}
	
