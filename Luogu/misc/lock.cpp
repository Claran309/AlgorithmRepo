#include <bits/stdc++.h>
using namespace std;
char goal[5];
int ans,n1,n2,n3,n4,n5,n,f[10][10][10][10][10][10]/*10^6  1->n  后五个为密码*/;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> goal[0] >> goal[1] >> goal[2] >> goal[3] >> goal[4];
		n1 = goal[0]-'0',n2 = goal[1]-'0',n3 = goal[2]-'0',n4 = goal[3]-'0',n5 = goal[4]-'0';//分离密码 
		//cout << n1 << n2 << n3 << n4 << n5 << endl;
		//查找满足的且之前也满足的
		if(i == 1){
			for(int j = 0;j <= 9;j++){
				int t1 = n1+j,t2 = n2+j,t3 = n3+j,t4 = n4+j,t5 = n5+j;
				if(t1 >= 10) t1%=10; if(t2 >= 10) t2%=10; if(t3 >= 10) t3%=10; if(t4 >= 10) t4%=10; if(t5 >= 10) t5%=10;
				f[1][t1][n2][n3][n4][n5] = 1;
				f[1][n1][t2][n3][n4][n5] = 1;
				f[1][n1][n2][t3][n4][n5] = 1;
				f[1][n1][n2][n3][t4][n5] = 1;
				f[1][n1][n2][n3][n4][t5] = 1;
				//转动一个
				f[1][t1][t2][n3][n4][n5] = 1;
				f[1][n1][t2][t3][n4][n5] = 1;
				f[1][n1][n2][t3][t4][n5] = 1;
				f[1][n1][n2][n3][t4][t5] = 1;
				//转动两个 
			}
		}else{
			for(int j = 0;j <= 9;j++){
				int t1 = n1+j,t2 = n2+j,t3 = n3+j,t4 = n4+j,t5 = n5+j;
				if(t1 >= 10) t1%=10; if(t2 >= 10) t2%=10; if(t3 >= 10) t3%=10; if(t4 >= 10) t4%=10; if(t5 >= 10) t5%=10;
				if(f[i-1][t1][n2][n3][n4][n5] == 1) f[i][t1][n2][n3][n4][n5] = 1;
				if(f[i-1][n1][t2][n3][n4][n5] == 1) f[i][n1][t2][n3][n4][n5] = 1;
				if(f[i-1][n1][n2][t3][n4][n5] == 1) f[i][n1][n2][t3][n4][n5] = 1;
				if(f[i-1][n1][n2][n3][t4][n5] == 1) f[i][n1][n2][n3][t4][n5] = 1;
				if(f[i-1][n1][n2][n3][n4][t5] == 1) f[i][n1][n2][n3][n4][t5] = 1;
				//转动一个
				if(f[i-1][t1][t2][n3][n4][n5] == 1) f[i][t1][t2][n3][n4][n5] = 1;
				if(f[i-1][n1][t2][t3][n4][n5] == 1) f[i][n1][t2][t3][n4][n5] = 1;
				if(f[i-1][n1][n2][t3][t4][n5] == 1) f[i][n1][n2][t3][t4][n5] = 1;
				if(f[i-1][n1][n2][n3][t4][t5] == 1) f[i][n1][n2][n3][t4][t5] = 1;
				//2个 
			}
		}
	}
	int w1 = 0;
	int w2 = 0;
	for(int i1 = 0;i1 <= 9;i1++)
		for(int i2 = 0;i2 <= 9;i2++)
			for(int i3 = 0;i3 <= 9;i3++)
				for(int i4 = 0;i4 <= 9;i4++)
					for(int i5 = 0;i5 <= 9;i5++)
						if(f[n][i1][i2][i3][i4][i5] != 0) {
							ans++;
							//cout << i1 << i2 << i3 << i4 << i5 << endl;
						}
	ans-=n;
	cout << ans;
	return 0;
}
