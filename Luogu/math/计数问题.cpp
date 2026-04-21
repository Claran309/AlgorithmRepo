#include <bits/stdc++.h>
using namespace std;
int cnt(int m,int t){
    c = 0;
	while(m){
		if(m % 10 == t) c++;
		m=m / 10;
	}
	return c;
}

int main(){
	int re = 0;
	int x,y;
	cin >> x >> y;
	for(int i = 0;i <= x;i++) re += cnt(i,y);
	cout << re;
	return 0;
}

