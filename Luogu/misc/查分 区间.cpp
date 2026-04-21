#include <bits/stdc++.h>
using namespace std;
int n,m,x,b[10000001],s[10000001],ca,f,l,add;

void change(int front,int last,int add){
	b[front] += add;
	b[last + 1] -= add;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> x;
		change(i,i,x);
	}
	while(m--){ 
		cin >> ca >> f >> l >> add;
		if(ca == 1) change(f,l,-add);
		else change(f,l,add);
	} 
	for(int i = 1;i <= n;i++) s[i] = s[i-1] + b[i];
	int k,kk;
	cin >> k >> kk;
	cout << s[kk] - s[k];
	return 0;
}  
