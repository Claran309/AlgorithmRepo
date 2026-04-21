#include <bits/stdc++.h>
using namespace std;
int vertex,edge,vex[100],x,y,input;
bool cnt;
struct Edge{
	int to,next;
} path[100];
void create_graph(int,int,int);
void lookfor_vertex(int);
int main(){
	memset(vex,-1,sizeof(vex));
	cin >> vertex >> edge;
	for(int i = 1;i <= edge;i++){
		cin >> x >> y;
		create_graph(x,y,i);
	}//GET -> 
	cin >> input;
	system("CLS");
	cout << input;
	lookfor_vertex(input);
	return 0;
} 
void lookfor_vertex(int nextt){
	if(cnt == false) {
		cout << " -> " << path[vex[nextt]].to;
		cnt++;
		if(path[vex[nextt]].next != -1) lookfor_vertex(path[vex[nextt]].next);
	}else{
		cout << " -> " << path[nextt].to;
		if(path[nextt].next != -1) lookfor_vertex(path[nextt].next);
    }
}
void create_graph(int x,int y,int i){
	path[i].to = y;
	path[i].next = vex[x];
	vex[x] = i;
}
