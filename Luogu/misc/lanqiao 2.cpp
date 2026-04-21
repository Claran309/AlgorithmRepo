#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a,ans;

long long leng_num(long long num){
	long long lengg = 1;
	while(num > 1){
		num/=10;
		lengg++;
	}
	return lengg;
}

bool real_num(long long n){
	long long len = leng_num(n);
	long long leng = 100,prev = 0;
	prev = n%10;
	for(long long i = 2;i <= len;i++){
		if(n/10<1) return false;
		if(n%leng/(leng/10) <= prev){
			prev = n%leng/leng*10;
			//cout << n%leng/(leng/10) << " " << leng << endl;
			leng*=10;
		}else return false;
	}
	return true;
}

int main(){
	cin >> a;
	//cout << real_num(a);
	for(long long i = 1;i <= a;i++){
		if(real_num(i)) ans++;
	}
	cout << ans-1;//GREAT
	return 0;
}
