#include <cstring>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

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

void wout(char a,int c){
	for(int i = 0;i < c;i++){
		cout << a;
		_sleep(56);
	}
}

int num_length(int number){
	int i;
	while(number > 0){
		number /= 10;
		i++;
	}
	return i;
}
