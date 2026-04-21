#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int>& stk){ 
	stack<int> help_stack;
	int pop,temp;
	while(!stk.empty()){ 
		pop = stk.top();
		stk.pop();
		if(help_stack.empty()) help_stack.push(pop);
		else{ 
			while(!help_stack.empty() && pop > help_stack.top()){ 
				temp = help_stack.top();
				help_stack.pop();
				stk.push(temp);
			} 
			help_stack.push(pop);
		} 
	} 
	while(!help_stack.empty()){ 
		stk.push(help_stack.top());
		help_stack.pop();
	} 
} 
void one_print_stk(stack<int>& stk){ 
	while(!stk.empty()){ 
		cout << stk.top() << " ";
		stk.pop();
	} 
} 
int main(){ 
	system("color a");
	stack<int> stk;
	int a,b;
	cin >> b;
	int s[b];
	system("CLS");
	cout << "宁即将输入" << b << "个数："; 
	for(int i = 0;i < b;i++){ 
		cin >> a;
		stk.push(a);
    } 
    system("CLS");
    cout << "宁输入了" << b << "个数：            ";
    for(int i =0;!stk.empty();i++){ 
    	s[i] = stk.top();
    	stk.pop();
    	cout << s[i] << " ";
	} 
	for(int i = 0;i < b;i++){ 
		stk.push(s[i]);
	} 
    sort_stack(stk);
    cout << endl;
    cout << "已将" << b << "个数栈排序(从大到小)：";
    one_print_stk(stk);
	return 0;
} 
