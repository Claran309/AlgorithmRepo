#include <bits/stdc++.h>
using namespace std;
long long ma[23][23],horsex,horsey,endx,endy;
int main(){
	cin >> endx >> endy >> horsex >> horsey;
	horsex++;
	horsey++;
	endx++;
	endy++;
	ma[1][0]=1;
	for(long long i = 1;i <= endx;i++)
	for(long long j = 1;j <= endy;j++){
		ma[i][j] = ma[i-1][j] + ma[i][j-1];
		if((i == horsex && j == horsey) || ( i == horsex-1 && j == horsey-2) || ( i == horsex-2 && j == horsey-1)  || ( i == horsex-2 && j == horsey+1) || ( i == horsex-1 && j == horsey+2) || ( i == horsex+1 && j == horsey-2) || ( i == horsex+2 && j == horsey-1)  || ( i == horsex+2 && j == horsey+1) || ( i == horsex+1 && j == horsey+2)){
			ma[i][j] = 0;
			//cout << i << " " << j << " over!!!" << endl;;
		}
	}
	for(int i = 1;i <= endx;i++){
		for(int j = 1;j <= endy;j++){
		cout << ma[i][j] << " ";
		}
		cout << endl;
	}
	cout << ma[endx][endy];
	return 0;

}
