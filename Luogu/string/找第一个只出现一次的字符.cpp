#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[100001];
	gets(s);
	int cnt = 0;
	for(int i = 0;i <= strlen(s);i++){
		
		cnt = 0;
		for(int j = 0;j < strlen(s);j++){
			if(s[j] == s[i]){
				cnt++;
			}
		}
		
		if(cnt == 1){
			printf("%c",s[i]);
			return 0;
		}
	}
	printf("no");
	
	
	
	
	return 0;
}
