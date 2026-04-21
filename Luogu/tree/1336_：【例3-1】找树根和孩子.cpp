#include <bits/stdc++.h>
using namespace std;
int ans[10],nd,n,x,y,h,w,ph,pw,anss;
int main(){
	cin >> nd >> n;
	for(int i = 0;i < n;i++){
		cin >> x >> y;
		if(i == 0) anss = x;
		ans[y] = x;
	}
	for(int i = 0;i < 10;i++){
		if(ans[i] != 0){
			w = ans[i];
			h++;
			if(h > ph){
				ph = h;
				pw = w;
			}
		}
	}
	//cout << pw << "  ";
	cout << anss << endl << pw << endl;;
	for(int i = 0;i < 10;i++){
		if(ans[i] == pw){
			cout << i << " ";
		}
	}
	return 0;
}
