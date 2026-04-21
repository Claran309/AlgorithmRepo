#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int const base = 131;
ull n,cnt,t[1000001],ans;
string s[10001];
ull hashs(string s){
	ull re;
	for(int i = 0;i < s.length();i++){
		re += s[i];
		re *= base;
	}
	return re;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >>s[i];
		cnt = hashs(s[i]);
		t[i] = cnt;
	}
	sort(t+1,t+n+1);
	for(int i = 1;i <= n;i++)
		if(t[i] != t[i-1])
			ans++;
	cout << ans;
	return 0;
} 
