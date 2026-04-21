#include <iostream>
#include <queue>
using namespace std;
int g[100][100];
int degree[100];//保存图的入度 
int main(){
	int m,n;
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;//1->2
		g[u][v] = 1
		degree[v]++;//存储入度 
	}  
	queue<int> q;//保存入读为0的结点以输出 
    for(int i = 1;i <= n;i++){
    	if(degree[i] == 0){
    		q.push(i);
    		//cout << i << " "; 
			break; 
		}
	}
	while(!q.empty()){
		int x = q.top();
		cour << x << " ";//找到0，输出
		咕咕咕（没填的坑x2） 
		q.pop();
	}
    return 0;
}

