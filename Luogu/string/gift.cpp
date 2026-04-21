#include <bits/stdc++.h> 
using namespace std;


void wout(string a,int c){
	for(int i = 0;i < c;i++){
		cout << a;
		_sleep(50);
	}
}

void sout(string s){
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i] != '.'){
			cout << s[i];
			_sleep(55);
		}else{
			cout << s[i];
			_sleep(180);
		}if(s[i] == '\\' && s[i+1] == 'n'){
			cout << endl;
		}
	}
}

int main(){ 
	sout("ewr wer e\nw");
	wout("Ÿoñj ",10000);
	return 0;
} 
