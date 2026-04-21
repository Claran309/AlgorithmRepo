#include <bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > q;
long long n,x,s,a,b;
int main(){
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> x;
		q.push(x);
	}
	while(q.size() > 1){
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		s += a+b;
		q.push(a+b);
	}
	cout << s;
	return 0;
}
