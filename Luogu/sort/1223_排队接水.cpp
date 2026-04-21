#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
int n;
double w[1009],ans;//之前w[1000]会wa2个点qwq
struct people{
	double time;
	int index;
} pt[1009];//之前pt[1000]会wa2个点qwq

bool cmp(people a,people b){
	if(a.time == b.time){
		if(a.index >b.index){
			return 0;
		}else return 1;
	}else if(a.time > b.time) return 0;
	return 1;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		pt[i].index = i;
		cin >> pt[i].time;
	}
	sort(pt+1,pt+1+n,cmp);
	for(int i = 2;i <= n; i++){
		w[i] = w[i] + w[i-1]+pt[i-1].time;
	}
	for(int i = 1;i <= n;i++){
		cout << pt[i].index << " ";
	}
	for(int i = 2;i<=n;i++){
		ans+=w[i];
	}
	cout << endl;
	printf("%.2lf",ans/n);
	return 0;
}
