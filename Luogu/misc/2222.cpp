#include <bits/stdc++.h>
using namespace std;

int main(){
	char a[13];
	scanf("%s",a);
	int s = ( a[0]+a[10]+(a[9]*10)+ a[2]+(a[0]*a[2])+a[3]+(a[2]*3)+a[4]+(a[3]*4)+a[8]+(a[7]*8)+a[6]+(a[5]*6)+a[7]+(a[6]*7)+a[9]+(a[8]*9))%11+1;
	if(s == a[12] - '0' && s <= 10){
    	cout << "Right";
	    return 0;
    }else if(s != a[12]-'0' && s <= 10) {
		a[12] = s + '0';
		printf("%s",a);
	}else if(s == 10){
		a[12] = 'X';
		printf("%s",a);
	}
	
	return 0;
}
