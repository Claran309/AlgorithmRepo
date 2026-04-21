#include <bits/stdc++.h>
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

int main(){
	stack<int> stk;
	int a[10] = {3,7,1,6,9,2,0,5,4,2};
	for(int  i= 0;i < 10;i++) stk.push(a[i]);
	sort_stack(stk);
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop(); 
	}
	return 0;
}
