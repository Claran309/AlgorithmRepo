//10100101101
//100000011110000101001100
//1110010111
//1011011100011110000011100010
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char letter[27] = {0,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
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
class Number{
private:
	string s;
	int len;
public:
	Number(string s){
		this->s = s;
		this->len = this->s.length();
	}//---
	void debug(){
		cout << len;
	}
	string resrting(){
		return this->s;
	}
	int StringToInt(string ss){
		char sss[1000],s[1000];
		for(ll i = 0;i <= ss.length()-1;i++){
			sss[i] = ss[ss.length()-1-i];
		}
		for(ll i = 0;i <= strlen(sss);i++){
			s[i] = sss[strlen(sss)-1-i];
		}
		ll ans = 0,i = strlen(s) - 1,j = 1,cnt = 1;
		while(true){
			ans = (s[i] - '0')*j + ans;
			j *= 10; 
			i--; 
			cnt++;
			if(cnt > strlen(s)) break;
		}
		return ans;
	}
	int BToD(ll a){
		ll b = 0,m = 0,k = 0;
		while(a != 0){
			m = a % 10;
			a /= 10;
			b += m*pow(2,k++);
		}
		return b;
	}//---
	string NumToString(ll a){
		char s[1000],t[1000];
		int cnt = 0;
		while(a >= 1){
			s[cnt] = char(a % 10 + '0');
			a = a / 10; 
			cnt++; 
		} 
		int leng = strlen(s) - 1;
		for(int i = 0,cnt = leng - 1;i < leng;i++,cnt--)
			t[i] = s[cnt];
		return t;
	}//---
	ll StringToNum(string s){
		
	}//---
	void DtoLetter(string s){
		string ans;
		sout("您想要的答案可能是：\n");
		for(int i = 0;i < s.length();i++){
			ans[i] = letter[s[i] - '0'];
			cout << ans[i]; _sleep(30);
		}
	}//---
	//DToB,DToLetter,LetterToD,MobileMode
	//void start(){
		
	//}
};
string in;
int main(){
	getline(cin,in);
	Number first = Number(in);
	cout << first.resrting() << endl;
	cout << first.StringToInt(first.resrting()) << endl;
	cout << first.BToD(first.StringToInt(first.resrting())) << endl;
	cout << first.NumToString(first.BToD(first.StringToInt(first.resrting()))) << endl;
	first.DtoLetter(first.NumToString(first.BToD(first.StringToInt(first.resrting()))));
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
void sout(string);
string IntArray_d_StringArray_b(int);
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
	}
	cout << IntArray_d_StringArray_b(int_d);
	return 0;
}
string IntArray_d_StringArray_b(int IntArray_b){
	char MachineArray_b[1000001];
	string answer;
	sprintf(MachineArray_b,"%o",IntArray_b);
	for(int i = 0;MachineArray_b[i];i++) answer += dui[MachineArray_b[i]-'0'];
	return answer;
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
*/ 
