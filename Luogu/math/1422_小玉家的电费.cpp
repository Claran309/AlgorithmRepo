#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	float s = 0;
	cin >> a;
	if(a <= 150){
		s = a * 0.4463;
		printf("%.1f",s);
	}else if(a > 150 && a <= 400){
		s = 150 * 0.4463 + (a - 150) * 0.4663;
		printf("%.1f",s);
	}else if(a > 400){
		s = (a - 400) * 0.5663 + 150 * 0.4463 + (400 - 150) * 0.4663;
		printf("%.1f",s);
	}
	return 0;
}
