#include <iostream>
using namespace std;


//保存图的二位数组 
int g[15][15];

#define MAXDIS 100000

int dist[15];
int visit[15];//全是-0 

main(){
	
	int vertex, edge;
	cin >> vertex >> edge;
	
	for(int i = 0; i < 15;i++){
		for(int j = 0; j < 15; j++){
			g[i][j] = MAXDIS;
		}
		g[i][i] = 0;
	}
	
	for(int i = 1; i<= edge; i++){
		int x, y, w;
		cin >> x >> y >> w;
		g[x][y] = w;
		g[y][x] = w;
	}
	for(int i = 1; i <= vertex; i++){
		dist[i] = MAXDIS;
	}
	
	
	//最短路
	//选多少次点 
	dist[1] = 0; 
	for(int i = 1; i <= vertex; i++){
		
		//找到中转点 
		int tmp = MAXDIS, pos;
		for(int j = 1; j <= vertex; j++){
			if(!visit[j]&&dist[j] < tmp){
				tmp = dist[j];
				pos = j;
			}
		}
		//pos = 1
		visit[pos] = 1;
		
		//重复更新路径 
		for(int j = 1; j <= vertex; j++){
			if(!visit[j]&&g[pos][j]!=MAXDIS){//j = 4
				dist[j] = min(dist[j], dist[pos]+g[pos][j]);
				//dist[4] = min(dist[4], dist[1]+g[1][4])
			}
		}
	} 
	
	for(int i = 1; i <= vertex; i++){
		cout << dist[i] << " ";
	}
	cout << endl;
	cout << "1-6最短路为:" << dist[vertex];
	
	
	return 0;
} 
