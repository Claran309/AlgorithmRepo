/*
栈:
代码:
push();  从栈顶插入一个数 
top();   获取栈顶的值 
pop();   从删除当前栈顶的值 
size();  获取栈中的元素个数 
empty(); 检查栈顶元素是否为空，若为空返回1(true)，否则返回0(false) 
	*/ 
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;//创建一个栈，用来储存 int 整形，名字叫做 s
	s.push(1);//把 1 进栈 
	s.push(3);//把 3 进栈
	cout << s.top() << endl;//获取当前的栈顶
	s.push(9);//把 9 进栈
	s.pop();//删除 9（top） 
	s.pop();//删除 3（top） 
	cout << s.top() << endl;//打印栈顶 1 
	s.pop(); 
	cout << s.size() << endl;// 打印 栈中的元素个数 
	cout << s.empty() << endl;//  查栈顶元素是否为 空  返回 1(true)
    return 0;
}
