#include <bits/stdc++.h>
#define green system("color 0a")
using namespace std;
struct c{
	int ch,ma,en;
} f[10];

bool cmp(c a,c b){
	if(a.ch+a.en+a.ma>b.ch+b.en+b.ma) return 1;
	else return 0;
}



int main(){
	green;
	int a;
	cin >> a;
	for(int i = 0;i < a;i++){
		cin >> f[i].ch >> f[i].ma >> f[i].en;
	}
	sort(f,f+a,cmp);
	system("CLS");
	for(int i = 0;i < a;i++)cout << f[i].ch << " " << f[i].ma << " " << f[i].en  <<endl;
	return 0;
}
