#include <bits/stdc++.h>
using namespace std;
bool coin,win[9];
int in,cnt;
char chess[10] = {'0','1','2','3','4','5','6','7','8','9'};
void sout(string s){
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i] != '.'){
			cout << s[i];
			_sleep(15);
		}else{
			cout << s[i];
			_sleep(50);
		} 
		if(s[i] == '\\' && s[i+1] == 'n'){
			cout << endl;
		}
	}
}
void print(){
	sout(" ");
	cout << chess[1];
	sout(" | ");
	cout << chess[2];
	sout(" | ");
	cout << chess[3] << endl;
	sout("----------\n");
	sout(" ");
	cout << chess[4];
	sout(" | ");
	cout << chess[5];
	sout(" | ");
	cout << chess[6] << endl;
	sout("----------\n");
	sout(" ");
	cout << chess[7];
	sout(" | ");
	cout << chess[8];
	sout(" | ");
	cout << chess[9] << endl;
}
int main(){
	system("mode con cols=35 lines=10");
	srand(time(NULL));
	coin = rand()%2;
	while(true){
		print();
		if(!coin){
			sout("这局宁下棋,aren't you lucky!\n"); 
			sout("请输入宁棋子的位置:");
			cin >> in;
			if(chess[in] == 'O'){
				sout("宁违反了游戏规则!给爷爬!");
				return 0;
			}
			chess[in] = 'X';
			coin = true;
		}else{
			sout("这局电脑下棋,aren't you lucky!\n");
			while(true){
				srand(time(NULL));
				in = rand()%9 + 1;
				if(chess[in] != 'X' and chess[in] != 'O'){
					chess[in] = 'O';
					break;
				}
			}
			coin = false;
		}
		cnt++;
		sout("按下回车键以继续......"); 
		getchar();
		system("CLS");
		win[0] = (chess[1] == chess[2]) && (chess[2] == chess[3]);
		win[1] = (chess[4] == chess[5]) && (chess[5] == chess[6]);
		win[2] = (chess[7] == chess[8]) && (chess[8] == chess[9]);
		win[3] = (chess[1] == chess[4]) && (chess[4] == chess[7]);
		win[4] = (chess[2] == chess[5]) && (chess[5] == chess[8]);
		win[5] = (chess[3] == chess[6]) && (chess[6] == chess[9]);
		win[7] = (chess[3] == chess[5]) && (chess[5] == chess[7]);
		win[8] = (chess[1] == chess[5]) && (chess[5] == chess[9]);
		if(win[0] or win[1] or win[3] or win[4] or win[5] or win[6] or win[7] or win[8])
			if(coin == 1){
				cout << "宁赢了!";
				break;
			}
			else{
				cout << "乐色,宁输了！";
				break;
		}
		if(cnt == 9){
			cout << "乐色,平局！";
			break;
		}
	}
	return 0;
} 
