#include <bits/stdc++.h>
using namespace std;

int main(){
	stack<int> que;
	int a;
	int x,y;
	
	cin >> a;
	int index[a][4];
	for(int i =0;i < a;i++){
		for(int j = 0;j < 4;j++){
			cin >> index[i][j]; 
		}
	}
	cin >> x,y;
	for(int i =0;i < a;i++){
		for(int j = 0;j < 4;j++){
			if(x > i && x < i+x || y > j && y < j+y){
				que.push(a);
			}
		}
	}
	if(que.size() != 0) cout << que.top();
	else cout << "-1";
	return 0;
}
