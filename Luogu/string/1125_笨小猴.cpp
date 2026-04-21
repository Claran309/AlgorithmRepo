#include <bits/stdc++.h>
using namespace std;

int F(string a){
	int n = a.length();
	int w;
	int zimu_cishu[n];
	char c,b[n];
	for(int i = 0;i < n;i ++){
		b[i] = a[i];
	}
	for(int i = 0;i < n;i++){
		c = a[i];
		w = a.find(c);
		while(w != -1){ 
		    zimu_cishu[i]++;
			w = a.find(c,w+1);
		}  
		for(int i = 0;i < n;i++) a[i] = b[i];
	} 
	sort(zimu_cishu,zimu_cishu+n);
	int frist = zimu_cishu[0];
	cout << frist << endl;
	int last = zimu_cishu[n-1];
	cout << last << endl;
	return last - frist;
}

bool zhishu(int n){
    if (n == 0 || n == 1)
    return false;
    if (n == 2)
    return true;
    for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
    return false;
    return true;
}

int main(){
	char s[100];
	scanf("%s",s);
	if(zhishu(F(s)) == true) {
		cout << "Lucky Word" << endl;
		cout << F(s);
	}else{
		cout << "No Answer" << endl;
		cout << "0";
	}
	return 0;
}
