#include <bits/stdc++.h>
using namespace std;
int l[30],r[30];
string fr,mid,back;
void dfs(int l1,int r1,int l2,int r2){
	if(l1 > r1 || l2 > r2) return;
	int i = mid.find(fr[l1]);
	dfs(l1+1,l1+i-l2,l2,i-1);//1->去掉刚刚查找的那个节点 2->左子树边界 3->左子树 4->左子树 
	dfs(l1+i-l2+1,r1,i+1,r2);
	cout << fr[l1];
}
int main(){
	cin >> mid >> fr;
	dfs(0,fr.length()-1,0,fr.length()-1);
	return 0;
}
