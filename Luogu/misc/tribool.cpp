ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>//40pts   3 4 5 6 10:30 40mins
using namespace std;
int t,c,n,m,x,y,bl[100001];
char in;
int ans;
int main(){
	//freopen("tribool.in","r",stdin);
	//freopen("tribool.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		memset(bl,1,sizeof(bl));
			for(int i = 1;i <= m;i++){
				cin >> in;
				if(in == 'F' || in == 'T' || in == 'U')
					cin >> x;
				else if(in == '-' || in == '+')
					cin >> x >> y;
				if(in != 'U')
					bl[x] = 1;
				else if(in == 'U') bl[x] = 0;
			}
			for(int i = 1;i <= n;i++){
				if(bl[i] == 0) ans++;
				//cout << bl[i] << " ";
			}
			cout << ans << endl;
			ans = 0;
		}
	
	return 0;
}
/*
//ios::sync_with_stdio(0);
//cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>//40pts   3 4 5 6 10:30 40mins
using namespace std;
int t,c,n,m,x,y,bl[100001];
char in;
int ans;
int father[100001];
int find(int x){
	if(father[x] != x) father[x] = find(father[x]);
	return father[x];
}
void unionn(int x,int y){
	father[y] = x;
}
int main(){
	//freopen("tribool.in","r",stdin);
	//freopen("tribool.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		memset(bl,1,sizeof(bl));
		for(int i = 1;i <= n;i++) father[i] = i;
			for(int i = 1;i <= m;i++){
				cin >> in;
				if(in == 'F' || in == 'T' || in == 'U')
					cin >> x;
				else if(in == '-' || in == '+')
					cin >> x >> y;
				if(in == '+')
					unionn(x,y);
				if(in == 'U') bl[find(x)] = -1;
			}
			for(int i = 1;i <= n;i++){
				if(bl[find(i)] == 0) ans++;
				//cout << bl[i] << " ";
			}
			cout << ans << endl;
			ans = 0;
		}
	
	return 0;
}
*/
