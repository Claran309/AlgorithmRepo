#include <bits/stdc++.h>
using namespace std;
queue<int> q; 
int  linker[9][9]={{0,0,0,0,0,0,0,0,0},     
                   {0,1,0,0,0,1,0,1,1},
                   {0,0,1,1,1,1,0,1,1},
               	   {0,0,1,1,0,0,1,1,1},
                   {0,0,1,0,1,1,1,0,1},
                   {0,1,1,0,1,1,1,0,0},
               	   {0,0,0,1,1,1,1,1,0},
                   {0,1,1,1,0,0,1,1,0},
                   {0,1,1,1,1,0,0,0,1}};
int visit[9];
int ma[9];

void PUTOUT(){
	cout << "H";
	int x = 8;
	int i = 0;
	while(i!=2){ 
		cout << "-->" << char(ma[x]+64);
		x = ma[x];
		i++;
	}
}

void bfs(int begin){
	q.push(begin);
	visit[begin] == true;
	while(!q.empty()){
		int i,x = q.front();
		q.pop();
		for(i = 1;i <= 8;i++){
			if(linker[x][i] == false && visit[i] == false){
				q.push(i);
				visit[i] == true;
				ma[i] = x;
				if(i == 8){
					PUTOUT();
					while(!q.empty())
						q.pop();
					break;
				} 
			}
		}
	}
}

int main(){
	bfs(1);
	return 0;
}
