#include <bits/stdc++.h>
using namespace std;
string s,out;
int n,m,cnt,ans;
int main(){
	cin >> s;
	cin >> n >> m;
	cin >> out;
	for(int i = 0;i < s.length();i++)
		if(s[i] >= '0' && s[i] <= '9' && s[i+1] == '+')cnt += s[i] - '0';
	if(n*m >= cnt) cout << "Yes" << endl;
	else cout << "No" << endl;;
	for(int i = 0;i <= out.length();i++)
		if(out[i] == '_') ans++;
	cout << ans << endl; 
	for(int i = out.length()-1;i >= 0;i--)
		if(out[i] != '_') cout << out[i];
	return 0;
}
