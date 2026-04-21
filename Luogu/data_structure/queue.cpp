// ±º‰∏¥‘”∂»£∫O(3n) 
#include <bits/stdc++.h>
using namespace std;
struct im{
	int e_num,w_num; 
} p[10000001];
int minn=INT_MAX,n,last;
string s;
int main(){
	cin >> n >> s;
	for(int i = 0;i < n;i++)
		if(s[i] == 'E'){
			p[i].e_num = 1 + p[last].e_num;
			last = i;
		}else p[i].e_num = p[last].e_num;
	for(int i = n-1;i >= 0;i--)
		if(s[i] == 'W'){
			p[i].w_num = 1+ p[last].w_num;
			last = i;
		}else p[i].w_num = p[last].w_num;
	for(int i = 0;i < n;i++){
		p[i].e_num = p[i].e_num+p[i].w_num-1;
		p[i].e_num = n-1-p[i].e_num;
		minn = min(minn,p[i].e_num);
	}
	cout << minn;
	return 0;
}
