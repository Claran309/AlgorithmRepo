#include <bits/stdc++.h>
using namespace std; 
int ask,n,ina,m;
set<int> s;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> ina;
		s.insert(ina);
	}
	for(int i = 1;i <= m;i++){
		cin >> ask;
		int t = 1;
		for(set<int>::iterator it = s.begin();it != s.end();it++){ 
			if(t == ask){
				cout << *it << endl;
				s.erase(it);
			}
			t++; 
		} 
		if(t == ask) cout << "last" <<endl;
	}
	return 0;
}
