#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int> > q;//创建小根堆
	int n;
	cin >> n;
	//1. 存储数据 
	for(int i=1;i<=n;i++){
		int x;cin >> x;
		q.push(x); 
	}//q里面的果子 顶部最小
	//2. 合并
	int s = 0;
	while(q.size() > 1 ){
		int a = q.top() ;
		q.pop() ;
		int b = q.top() ;
		q.pop() ;
		s += a+ b ;
		q.push(a + b); 
	} 
	cout << s;
	return 0;
}
