#include <bits/stdc++.h>
using namespace std;
int s,e,f[100000001],v,n,c[10001],w[10001],m[10001];
string a11,b11;
int main(){
	cin >> a11 >> b11;
	if(a11[1] == ':') s+=(a11[0]-'0')*60+a11[2]*10+a11[3];
	else if(a11[2] == ':') s+=(a11[0]-'0')*10*60+(a11[1]-'0')*60+a11[3]*10+a11[4];
	if(b11[1] == ':') e+=(b11[0]-'0')*60+b11[2]*10+b11[3];
	else if(b11[2] == ':') e+=(b11[0]-'0')*10*60+(b11[1]-'0')*60+b11[3]*10+b11[4];
	v = e-s;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> c[i] >> w[i] >> m[i];
	for(int i = 1;i <= n;i++)
		if(m[i] == 0)
			for(int j = c[i];j <= v;j++) 
				f[j] = max(f[j],f[j-c[i]]+w[i]);
		else
			for(int j = v;j >= 0;j--)
				for(int k = 1;k <= m[i];k++)
					if(j >= k*c[i]) f[j] = max(f[j],f[j-k*c[i]]+k*w[i]);
	cout << f[v];
	return 0;
}
