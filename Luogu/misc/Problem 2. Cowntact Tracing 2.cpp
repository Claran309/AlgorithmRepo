//01110 -> 1   011110 -> 001100 2   0111110 1 01111110 2 01111111110   01111
#include <bits/stdc++.h>
using namespace std;
bool l,r,flag;
char s[500002];
int n,cow[500001],last,ans,length,sum,bn;
vector<int> block;
int main(){
	cin >> n >> s+1;
	for(int i = 1;i <= n;i++){
		if(s[i] == '1') cow[i] = 1;
		if(s[i] == '0') cow[i] = 0;
		if(cow[i] == 1)// {
			ans++;
		//	cout <<i<<endl;
	//	}
		if(i == 1) last = cow[i];
		if(i == 1 && cow[i] == 1) l = 1;
		if(i == n && cow[i] == 1) r = 1;
		if(cow[i] != last && last == 1){
			block.push_back(length);//算出连通块的长度 
			bn++;
			length = 0;
		}else if(cow[i] == 1) length++;
		last = cow[i];
	}
	if(r == 1) {
		block.push_back(length);
		bn++;
	}
	//cout << ans << endl;
	//cout << (int)block.size() << endl;
	while(true){//每次减2 
		for(int i = 0;i <= (int)block.size()-1;i++){
		//	if(i == 0 && l == 1 && bn > 1) block[i]-=1,sum+=1;
		//	else if(i == (int)block.size()-1 && r == 1) block[i]-=1,sum+=1;
		//	else block[i]-=2,sum+=2;
			block[i]-=2,sum+=2;
			if(block[i] <= 0) flag = 1;
		}
		if(flag == 1) {
			//if(l == 1) sum+=1;
			//if(r == 1) sum+=1;
			sum-=(2*(int)block.size());//减掉的个数 
			ans = ans-sum;//剩下的个数 
			break;
		}
	}
	cout << ans;
}
