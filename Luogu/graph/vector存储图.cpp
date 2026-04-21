#include <bits/stdc++.h>
using namespace std;
int vertex,Edge,x,y,z;
struct Edge{
	int to,value;
};
vector<Edge> G[5];
int main(){
	cin >> vertex >> edge;
	for(int i = 0;i <= edge;i++){
		cin >> x >> y >> z;
		edge e;
		e.to = x; e.value = z;
		G[x].push_back(e);
	}
	return 0;
}
