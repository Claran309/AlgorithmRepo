#include <ctime>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int guess_num,r,f;
void sout(string s){
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i] != '.'){
			cout << s[i];
			_sleep(25);
		}else{
			cout << s[i];
			_sleep(300);
		}if(s[i] == '\\' && s[i+1] == 'n'){
			cout << endl;
		}
	}
}
void guess(int yours,int deep){
    cin >> yours;
	cout << endl;
	if(yours > guess_num){
		cout << yours << " ";
		sout("猜大了，请再来一次！\n"); 
		guess(0,deep+1);
	}
	else if(yours < guess_num){
		cout << yours << " ";
		 sout("猜小了，请再来一次！\n");
		guess(0,deep+1);
	}
	else {
		cout << yours;
		sout(" 就是秘密数字！恭喜你猜对了！\n");
		return;
	} 
}
int main(){
	srand(time(0));
	sout("Hi，训练师！我们来玩一个猜数字游戏吧！\n");
	while(true){
		sout("你想从让随机数最小值为多少呢？\n");
		cin >> r;
		sout("你想从让随机数最大值为多少呢？\n");
		cin >> f;
		if(f - r <= 1){
			sout("你的最大值和最小值不符合规范哦~\n\n");
		}else break;
	}
	sout("请猜一个"); 
	cout << r;
	sout("到");
	cout << f;
	sout("之间的秘密数字（不包括");
	cout << r;
	sout("和");
	cout << f;
	sout("）: ");
	guess_num = rand()/r%f;
	guess(0,0);
	return 0;
}
