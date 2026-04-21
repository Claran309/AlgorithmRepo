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
#include <ctime>
using namespace std;
int n,sum;
string answer;
void sout(string s){
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i] != '.'){
			cout << s[i];
			_sleep(5);
		}else{
			cout << s[i];
			_sleep(3);
		}if(s[i] == '\\' && s[i+1] == 'n'){
			cout << endl;
		}
	}
}
int main(){
	while(true){
		srand(time(0));//
		sout("石头剪刀布!");
		sout("你要出石头呢，还是剪刀呢，还是布？（若输入退出，可退出游戏）");
		cout << endl;
		cin >> answer;
		if(answer == "退出"){
			sout("你赢了");
			cout << sum ;
			sout("局！\n再......再见！！！"); 
			return 0;
		}
		n = rand()%3;//
		/*while(1){
			if(n != 1 || n != 2 || n!= 0){
				srand(time(0));
				n = rand()%3;
			}
			else break;
		}*/
		if(n == 0){ 
			if(answer == "石头")
				sout("你出了石头，电脑出了石头......\n平局！"); 
			else if(answer == "剪刀")
				sout("你出了剪刀，电脑出了石头......\n你输了！"); 
			else if(answer == "布") {
				sout("你出了布，电脑出了石头......\n你赢了！"); 
				sum++;
			}
		}else if(n == 1){ 
			if(answer == "石头") {
				sout("你出了石头，电脑出了剪刀......\n你赢了！");
				sum++; 
			}else if(answer == "剪刀")
				sout("你出了剪刀，电脑出了剪刀......\n平局！"); 
			else if(answer == "布") 
				sout("你出了布，电脑出了剪刀......\n你输了！"); 
		}else if(n == 2) {
			if(answer == "石头")
				sout("你出了石头，电脑出了布......\n你输了！"); 
			else if(answer == "剪刀") {
				sout("你出了剪刀，电脑出了布......\n你赢了！"); 
				sum++;
			}else if(answer == "布") 
				sout("你出了布，电脑出了布......\n平局！"); 
		}
		cout << endl << endl;
	}
	return 0;
} 
