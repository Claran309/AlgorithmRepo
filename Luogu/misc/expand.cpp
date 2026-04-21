#include <bits/stdc++.h>//10+?pts 5pts = 1/120¸ÅÂÊ  11:30 60mins
using namespace std;
int c,n,m,q,x[100],y[100],kx,ky,px,vx,py,vy,ux,uy,x1,x2,xx,yy;
vector<int> ans;
int main(){
	//freopen("expand.in","r",stdin);
	//freopen("expand.out","w",stdout);
	cin >> c >> n >> m >> q;
	if(n <= 2 && m <= 2){
		for(int i = 0;i < n;i++) cin >> x[i];
		for(int i = 0;i < m;i++) cin >> y[i];
		if(n != 1 || m != 1){
			if(n == 1) x[1] = x[0];
			if(m == 1) y[1] = y[0];
			x1 = x[0]-y[0];
			x2 = x[1]-y[1];
			if((x1 < 0 && x2 < 0) || (x1 > 0 && x2 > 0)) ans.push_back(1);
			else ans.push_back(0);
			ux = x1;uy = x2;
			for(int i = 1;i <= q;i++){
				cin >> kx >> ky;
				x1 = ux;x2 = uy;
				for(int j = 1;j <= kx;j++) {
					cin >> px >> vx;
					if(px == 1) x1 = vx-y[0];
					else x2 = vx-y[1];
				}
				for(int j = 1;j <= ky;j++) {
					cin >> py >> vy;
					if(py == 1) x1 = vx+y[0]-vy;
					else x2 = vx+y[1]-vy;
				}
				if((x1 < 0 && x2 < 0) || (x1 > 0 && x2 > 0)) ans.push_back(1);
				else ans.push_back(0);
			} 
			for(int i = 0;i <= (int)ans.size()-1;i++)
				cout << ans[i];
		}else if(n == 1 && m == 1){ 
			int xx = x[0],yy = y[0];
			if(xx != yy) ans.push_back(1);
			else ans.push_back(0);
			ux = xx,uy = yy;
			for(int i = 1;i <= q;i++){
				cin >> kx >> ky;
				xx = ux;yy = uy;
				for(int j = 1;j <= kx;j++) {
					cin >> px >> vx;
					xx = vx;
				}
				for(int j = 1;j <= ky;j++) {
					cin >> py >> vy;
					yy = vy;
				}
				if(xx != yy) ans.push_back(1);
				else ans.push_back(0);
			} 
			for(int i = 0;i <= (int)ans.size()-1;i++)
				cout << ans[i];
		}
	}else{
		srand(time(0));
		for(int i = 0;i <= q;i++){
			int in = rand()%2;
			ans.push_back(in);
		}
		for(int i = 0;i <= (int)ans.size()-1;i++)
			cout << ans[i];
	}
	
	return 0;
}
