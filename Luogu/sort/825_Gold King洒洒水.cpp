#include <bits/stdc++.h>
using namespace std;
double a[605],r,len,sum;
bool cmp(double a,double b){
	return a > b;
}

int main(){
	int n ;
	cin >> n;
	for(int i = 0; i <= n ;i++)
		cin >> a[i];
	sort(a+1,a+n+1;cmp);
	for(int i = 0; i <= n; i++){
		r = a[i]
		if(r >1) len = 2*sqrt(r*r-1);
		else len = 0;
		sum += len;
		cnt++;
		if(sum >= 20){
			cout << cnt << endl;
			return 0;
		} 
	} 
	return 0;
}
/*
#include <bits/stdc++.h> 
using namespace std;
float m,answer[15],n[15][600],nn[600];
int p[15];
float ans = 0,mlong = 20;
int cnt(float n,float a[]){
	
	    mlong = 20;
		for(int i = 0;i < n;i++){
			if(mlong >= 0){
				mlong -= sqrt((a[i]*a[i]-1));
				ans++;
				//cout << ans << " ";
			}
		}
	
	return ans;
}
//sqrt
bool cmp(float a,float b){
	if(a>b)return 1;
	else return 0;
}

int main(){
	cin >> m;
	for(int i = 0;i < m;i++){
		cin >> p[i];
		for(int j = 0;j < p[i];j++){
			cin >> n[i][j];
			nn[i] = n[i][j];
		}
		sort(nn,nn+p[i],cmp);
		answer[i] = cnt(p[i],nn);
	}
	for(int i = 0;i < m;i++) cout << answer[i] << endl;
	return 0;
}
*/
