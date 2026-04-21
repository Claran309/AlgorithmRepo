#include <bits/stdc++.h>
using namespace std;

struct per{
	bool way;
	int money,time;
} p[100000];


int many;
int rtime,ffftime[100000],fffmoney[100000];
int n,cnt,sum,j,anther_j;
int main(){
	cin >> n;
	for(int i = 0 ;i < n;i++) cin >> p[i].way >> p[i].money >> p[i].time;
	for(int i = 1 ;i < n;i++){
		if(p[i].way == false){
			many++;
			ffftime[j] = p[i].time;
			fffmoney[i] = p[i].money;
			j++;
			sum+=p[i].money;
		}
		if(p[i].way == true){
			for(int i = 0;i < j;i++){
				if(p[i].time - ffftime[i] <= 45 && many != false && p[i].money <= fffmoney[i]){
				p[i].money = 0;
				many--;
				sum+=p[i].money;
			}
			
			}
			
		}
		cout << "*" << sum << " ";
	}
	cout << sum;
	return 0;
} 
