#include <iostream>
#include <cstring>
#include <cstdio>
#define ull unsigned long long
using namespace std;
const int p = 131;
char dna[1000010];
int ans,m,l1,r1,l2,r2;
ull h[1000010],pows[1000010];
ull hashs(int l,int r){
	return h[r] - h[l-1] * pows[p,r-l+1];
}
int main(){
	cin >> dna+1 >> m;
	pows[0] = 1;
	int n = strlen(dna+1);
	for(int i = 1;i <= n;i++){
		h[i] = h[i-1]*p + dna[i]- 'a' + 1;
		pows[i] = pows[i-1]*p;
	}
	while(m--){
		cin >> l1 >> r1 >> l2 >> r2;
		if(hashs(l1,r1) == hashs(l2,r2)) 
			cout <<"Yes" <<endl;
		else cout << "No" << endl;
	}
	return 0;
}
https://imgse.com/i/pPnNRoR
https://imgse.com/i/pPnNgeJ
https://imgse.com/i/pPnN6L4
https://imgse.com/i/pPnN2w9
https://imgse.com/i/pPnNyyF
https://imgse.com/i/pPnNfF1
https://imgse.com/i/pPnNISK
https://imgse.com/i/pPnN4W6
https://imgse.com/i/pPnNhJx
https://imgse.com/i/pPnNoQO
https://imgse.com/i/pPnNTyD
