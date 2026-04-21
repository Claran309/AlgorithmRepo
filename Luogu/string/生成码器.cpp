#include <bits/stdc++.h>
using namespace std;
void sout(string);
string char_b,input,dui[8]={"000","001","010","011","100","101","110","111"};
char machine_b[1000001];
int int_array_b[1000001],int_array_d[1000001],int_b,int_d,k;
//be diligent! 7.15
int main(){//%B -> LETTER LIST
	getline(cin,input);
	k = 1;
	for(int i = 0;i < input.size();i++) int_array_d[i] = input[i] - '0';//其实一个sprintf就行... 
	for(int i = input.size()-1;i >= 0 ;i--){
		int_d = int_d + (input[i] - '0') * k;
		k *= 10;
	}//GET -> cout << int_d;
	sprintf(machine_b,"%o",int_d);
	for(int i = 0;machine_b[i];i++) char_b += dui[machine_b[i]-'0'];//char_b为int_d的二进制！GET！ 
	//--------------------------------以上为10转2 的 高级算法 
	cout << char_b;
	return 0;
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
		} 
		if(s[i] == '\\' && s[i+1] == 'n'){
			cout << endl;
		}
	}
}
