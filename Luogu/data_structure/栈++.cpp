#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main(){
	stack<int> s,c;
	int b,a;
	cin >> a;
	for(int i = 0;i < a;i++) {
		cin >> b;
		s.push(b);
	}
	while(!s.empty()){
		c.push(s.top());
		s.pop();
	}
	system("CLS");
	cout << "宁刚才输入的数为："
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	while(!c.empty()){
		cout << c.top() << " ";
		c.pop();
	}
	return 0;
} /*
    
*/
