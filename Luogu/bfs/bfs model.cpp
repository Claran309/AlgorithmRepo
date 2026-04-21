#include <bits/stdc++.h>
using namespace std;
queue<int> duilie;
int judge[10];
int map[100][100];

void bfs(int a){
	duilie.push(1);
	judge[1] == 0;
	while(!duilie.empty()){
		int out = duilie.front();
		duilie.pop();
		for(int i = 1;i <= n;i++)
			if(map[out][i] == 1 && judge[i] == 1){
				judge[i] == 0;
				duilie.push(i);
			}
	}
}

int main(){
	
	return 0;
}
