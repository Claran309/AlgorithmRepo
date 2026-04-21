#include <bits/stdc++.h>
using namespace std;
int n,a;
vector<int> v;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a;
		v.insert(lower_bound(v.begin(),v.end(),a),a);
		if(i%2 == 1) cout <<v[(i-1)/2] <<endl;
	}
	return 0;
}
