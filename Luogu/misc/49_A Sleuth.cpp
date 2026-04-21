#include <bits/stdc++.h>
using namespace std;
int i = 0;
int main(){
	char c[100];
	while(cin >> c[i]){
		i++;
	}
		if(c[i-2]=='A'||c[i-2]=='O'||c[i-2]=='U'||c[i-2]=='Y'||c[i-2]=='I'||c[i-2]=='E'||c[i-2]=='a'||c[i-2]=='o'||c[i-2]=='u'||c[i-2]=='y'||c[i-2]=='i'||c[i-2]=='e')//Ó·Ö×µÄÅÐ¶Ï
		cout<<"YES";
		else cout<<"NO";
	return 0;
 } 

