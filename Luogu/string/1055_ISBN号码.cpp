#include <bits/stdc++.h>
using namespace std;

int main(){
	char a[13];
	int s = 0,j = 0;
	for(int i = 1;i <= 13;i++) {
		cin >> a[i-1];
		if(a[i-1] != '-' && i != 13){
			j++;
			s = s + (a[i-1] - '0') * j;
		}
	}
	s = s % 11;
	if(s == a[12] - '0' || s == a[12] - 78) {
	    cout << "Right" << endl;
	    return 0;
	}
	else if(s != a[12] && s != 10) {
		for(int i = 0;i < 12;i++)
		cout << a[i];
		cout << s;
	}
	else if(s == 10) {
		for(int i = 0;i < 12;i++)
		cout << a[i];
		cout << "X";
	}
	return 0;
}
