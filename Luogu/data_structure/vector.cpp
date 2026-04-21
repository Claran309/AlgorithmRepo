#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	vector<int> g[5];//2ά 
	g[0].push_back(2);
	g[2].push_back(2);
	g[2].push_back(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	for(int i = 0;i < g[2].size();i++) cout << g[2][i] << " " ;
	return 0;
}
