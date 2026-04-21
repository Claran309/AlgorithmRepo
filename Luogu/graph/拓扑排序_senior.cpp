#include <bits/stdc++.h>
using namespace std;
int n,cv,r[101];
vector<int> v[101];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		while(true){
			cin >> cv;
			if(cv == 0) break;
			v[i].push_back(cv);//i -> cv
			r[cv]++;//存入度 
		}//存图 
	queue<int> q;
	for(int i = 1;i <= n;i++)
		if(!r[i]) q.push(i);//若入度为0 
	while(!q.empty()){
		int doing = q.front();
		q.pop();
		cout << doing << " ";
		for(int i = 0;i <= (int)v[doing].size()-1;i++){
			r[v[doing][i]]--;//更新入度 
			if(!r[v[doing][i]]) q.push(v[doing][i]);//维护队列,新加入入度为0的节点 
		}
	}
	return 0;
}
/*
5
0
4 5 1 0
1 0
5 3 0
3 0
*/
