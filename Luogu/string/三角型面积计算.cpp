#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
	
	char s[101];
	scanf("%s",s);
	for(int i = 0;i < strlen(s);i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = s[i] - 32;
		}
	}
    printf("%s",s);	
	return 0;
}

