#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int m[9][8] = {
{0,0,0,0,0,0,0,0},
{0,1,1,0,1,0,1,0},
{1,0,1,0,0,0,0,0},
{1,1,0,1,0,0,0,0},
{0,0,1,0,0,1,0,1},
{1,0,0,0,0,1,1,0},
{0,0,0,1,1,0,0,0},
{1,0,0,0,1,0,0,1},
{0,0,0,1,0,1,1,0}
},n = 8,p[8],d[8];
char c[9] = {0,'A','B','F','H','D','G','C','E'};
int main(){
	queue<int> que;
	que.push(1);
	p[1] = 1;
	while(!que.empty()){
		int out = que.front();
		que.pop();
		for(int i = 1;i <= n;i++)
			if(m[out][i] && !p[i]){
				if(i == 4){
					d[4] = out;
					break;
				}
				d[i] = out;
				p[i] = 1;
				que.push(i);
			}
	}
	cout << "A";
}
