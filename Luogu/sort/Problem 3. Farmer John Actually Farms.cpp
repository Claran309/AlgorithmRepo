#include <bits/stdc++.h>
using namespace std;
struct seed{
	int h,final,gr;
} d[500001];
bool cmp(seed x,seed y){
	return x.final < y.final;
}
int t,n,m,l,r;
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++)
			cin >> d[i].h;
		for(int i = 1;i <= n;i++)
			cin >> d[i].gr;
		for(int i = 1;i <= n;i++)
			cin >> d[i].final;
		sort(d+1,d+1+n,cmp);//期望：d[1].h > d[2].h 依据期望进行不等式修正
		for(int i = 1;i < n;i++){//d[i].h+d[i].gr*x > d[i+1].h + d[i+1].gr*x;
			//分类讨论上界与下界：上界：x<?  d[i+1].gr*x > d[i].gr*x 下界反之
			if(d[i+1].gr > d[i].gr)//上 <
			 	r = min(r,(int)((d[i].h-d[i+1].h)/(d[i+1].gr-d[i].gr)));
			else if(d[i+1].gr < d[i].gr)//下 > 
				l = max(l,(int)(ceil)((d[i+1].h-d[i].h)/(d[i].gr-d[i+1].gr)));
			if(r >= 0 && l >= 0 && l <= r){//是否违法 
				cout << l << endl;
			}
		}		
	}
	return 0;
}
