#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int>& s){ 
	stack<int> h;
	int top,tmp;
	while(!s.empty()){ 
		top = s.top();
		s.pop();
		if(h.empty()){ 
			h.push(top);
		}else{ 
			while(!h.empty() && top > h.top()){ 
				tmp = h.top();
				h.pop();
				s.push(tmp);
			} 
			h.push(top);
		} 
	} 
	while(!h.empty()){ 
		s.push(h.top());
		h.pop(); 
	} 
} 
 
int main(){ 
	system("color a");
	stack<int> s;
	s.push(6);
	s.push(9);
	s.push(5);
	s.push(3);
	s.push(1);
	s.push(2);
	sort_stack(s);
	while(!s.empty()){ 
		cout << s.top() << " ";
		s.pop();
	} 
	return 0;
} 
