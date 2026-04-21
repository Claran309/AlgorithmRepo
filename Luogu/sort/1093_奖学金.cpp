#include <bits/stdc++.h>
using namespace std;

struct c{
	int ch,ma,en,idx;
} f[100];

bool cmp(c a,c b){
	int az = a.ch+a.en+a.ma; 
	int bz = b.ch+b.en+b.ma;
	if(az > bz) return true;
	else if(az == bz && a.ch > b.ch) return true;
	else if(az == bz && a.ch == b.ch && a.idx < b.idx) return true;
	else return false;
}

int main(){
	system("color 0a");
	int a;
	cin >> a;
	for(int i = 1;i <= a;i++){
		cin >> f[i].ch >> f[i].ma >> f[i].en;
		f[i].idx = i;
	} 
	sort(f+1,f+a+1,cmp);
	for(int i = 1;i <= 5;i++) cout << f[i].idx << " " << f[i].ch+f[i].en+f[i].ma << endl;
	return 0;
}
