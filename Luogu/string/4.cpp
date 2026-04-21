#include <bits/stdc++.h>
using namespace std;
map<string,int> m;
bool check(string t){
	int len = t.size();
	int l = 0,r = len - 1;
	while(l < r){
		if(t[l] != t[r]) return false;
		else{
			l++; r++;
		}
	}
	return true;
}
int main(){
	string s;
	cin >> s;
	int ans, len = s.size();
	for(int i = 1;i <= len;i++)
		for(int j = 0;j <= len - i;j++){
			string t = s.substr(j,i);
			if(check(t) && !m[t]){
				ans++; m[t]++;
			}
		}
	cout << ans;
	return 0;
}
