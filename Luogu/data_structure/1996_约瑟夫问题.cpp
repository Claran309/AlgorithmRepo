#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	queue<int> q;
	for(int i = 1;i <= n;i++) q.push(i);
	int k = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		if(k == m){
			cout << t << " ";
			k = 1;
			continue;
		}
		q.push(t);
		k++;
	} 
	return 0;
}
