#include <iostream>
#include <queue>
using namespace std;
//先进先出
//头删尾出 
//push();pop();
//front();队头
//back();队尾 
int main(){ 
	system("color a");
	queue<int> que;
	que.push(1);
	que.push(2);
	quecush(3);
	while(!que.empty()){ 
		cout << que.front() << " ";
		que.pop();
	} 
	return 0;
} 
