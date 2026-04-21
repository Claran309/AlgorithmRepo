#include <bits/stdc++.h>
using namespace std;
int a,b,ans,fy,ly,months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int hws(int num){
	int sum = 0;
	while(num != 0){
		sum = sum*10+num%10;
		num /= 10;
	}
	return sum;
}
int main(){
	int sum2 = 0;
	cin >> a >> b;
	if(a == b && a == hws(a)){
		cout << 1;
		return 0;
	}
	fy = a%100000/10000+a%1000000/100000*10+a%10000000/1000000*100+a%100000000/10000000*1000;
	ly = b%100000/10000+b%1000000/100000*10+b%10000000/1000000*100+b%100000000/10000000*1000;
	for(int i = fy;i <= ly;i++)
		for(int j = 1;j <= 12;j++)
			for(int l = 1;l <= months[l-1];l++){
				sum2 = i * 10000 + j * 100 + l;
				if(sum2 == hws(sum2)) ans++;
			}
	cout << ans;
	return 0;
}
