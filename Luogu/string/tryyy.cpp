//#include "moreuse.h"
#include <iostream>
#include <cstring>
void sout(string s){
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i] != '.'){
			cout << s[i];
			_sleep(55);
		}else{
			cout << s[i];
			_sleep(180);
		} 
		if(s[i] == '\\' && s[i+1] == 'n'){
			cout << endl;
		}
	}
}
using namespace std;
int main(){
	sout("asjd/adasd/nasdn/");
	return 0;
}

