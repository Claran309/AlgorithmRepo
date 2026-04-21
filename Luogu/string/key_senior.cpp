// ±º‰∏¥‘”∂»£∫O(n~3n) 
#include <bits/stdc++.h>
using namespace std;
string c;
stack<int> s,out;
int main(){
	cin >> c;
	for(int i = 0;i < c.length();i++)
		if(c[i] == '0')
			s.push(0);
		else if(c[i] == '1')
			s.push(1);
		else if(c[i] == 'B' && s.size())
			s.pop();
	while(s.size()){
		int a = s.top();
		s.pop();
		out.push(a);
	}
	while(out.size()){
		cout << out.top();
		out.pop();
	}
	return 0;
}
