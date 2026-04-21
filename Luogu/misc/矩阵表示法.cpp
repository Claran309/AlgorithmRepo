#include <bits/stdc++.h>
#define map mapp
#define ma map
using namespace std;
int map[100][100],n,edge,v1,v2;
int main(){
	cin >> n >> edge;
	for(int i = 0;i <= edge;i++){
		cin >> v1 >> v2;
		map[v1][v2] = 1;
	}
	return 0;
}
