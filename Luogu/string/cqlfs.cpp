#include <bits/stdc++.h>
using namespace std;
struct test_score{
	int sc,th,sum,up;
	bool can = 0;
} s[1001];
int qq = 20,n,cnt1,cnt2,upp,answer[51],j;
char s[6];
bool cmp(test_score x,test_score y){
	if(x.sc > y.sc) 
	else if(x.sc == sc){
		if(x.sum > y.sum) return x;
		else return y;
	}else return y;
}

bool cmp2(test_score x,test_score y){
	if(x.up > y.up) return x;
	else if(x.up == y.up){
		if(x.sc > y.sc) return x;
		else return y;
	}else return y;
}
string = "lbwnb";
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i].sc;
		while(){
			//how do it putout!
			//i do'n know! 
			//just this, Or i can ac this problem!
		}
		//for(int i = 1;i <= s.length();i++){
		//	if(s[i] == 'A') upp+=100;
		//	if(s[i] == 'B') upp+=50;
		//	if(s[i] == 'C') upp+=20;
		//	if(upp >= 500){
		//		upp = 500;
		//		break;
		//	}
		//}
		s[i].sum = s[i].sc*0.7 + upp*0.3;
		s[i].th = i;
		s[i].up = upp;
	}
	sort(s,s+n,cmp);
	for(int i = 1;i <= 30;i++){
		s[i].can = 1;
	}
	sort(s,s+n,cmp2)
	for(int i = 1;i <= qq;i++){
		if(s[i].can == 0){
			s[i].can = 1;
		}else{
			qq++;
		}
	}
	sort(s,s+n,cmp);
	for(int i = 1;i <= n;i++){
		if(s[i].can == 1){
			cout << s[i].th << endl;;
		}
	}
	return 0;
}
