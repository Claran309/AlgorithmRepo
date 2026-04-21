#include <bits/stdc++.h>
using namespace std;
struct s{
	char n[8];
	int c,m,e,z;
} st[1001];
bool cmp(s a,s b){
	if (a.z > b.z) return 0;
	return 1;
}



int main(){
	int n;
	cin >> n;
	for(int i =0;i<n;i++){
		scanf("%s%d%d",st[i].n,st[i].c,st[i].m,st[i].e);
		st[i].z = st[i].c+st[i].m+st[i].e;
	}
	sort(st,st+1001,cmp);
	cout << st[0].n << " " << st[0].c << " " << st[0].m << " " <<st[0].e;
	return 0;
}
