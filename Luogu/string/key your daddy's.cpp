#include <bits/stdc++.h>
using namespace std;
stack<int> q,out;
int ans,cnt;
int main(){
	string s;
	cin >> s;
	ans = s[0] - '0';
	int a = s.length();
	for(int i = 1;i <= s.length();i++){
		if(s[i] == '1') q.push(1);
		if(s[i] == '0') q.push(0);
		if(s[i] == 'B'){
			cnt++;
			if(q.empty()) continue;
			else q.pop();
		}
	}
	if(s[0] == 'B' || a - cnt <= cnt){
		cout << "";
		return 0;
	}
	while(!q.empty()){
		out.push(q.top());
		q.pop();
	}
	cout << ans;
	while(!out.empty()){
		cout << out.top();
		out.pop();
	}
	return 0;
}
