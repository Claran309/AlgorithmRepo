#include <bits/stdc++.h>//70pts 9:50 80mins
using namespace std;
bool ncorrect;
int n,m,num[100][4],less[100],x,y,les,tha;
char s[100][300];
map<char,int> ma;
vector<int> ans;
int main(){
	//freopen("dict.in","r",stdin);
	//freopen("dict.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= 26;i++){
		char ii = i+96;
		ma[ii] = i;
		//cout << ma[ii] << " "; 
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < m;j++)
				cin >> s[i][j];
			num[i][0] = ma[s[i][0]],num[i][1] = ma[s[i][1]];
			if(num[i][0] >= num[i][1]){
				num[i][2] = 1,num[i][3] = 0;//2 小 3 大 
			}else num[i][2] = 0,num[i][3] = 1; 
		}
		for(int i = 1;i <= n;i++){
			x = ma[s[i][0]]; y = ma[s[i][1]];
			les = min(x,y),tha = max(x,y);
		//	printf("THE NECT Is 字符%c\n",s[i][0]);
			for(int j = 1;j <= n;j++){
				if(j == i )continue;
			//	printf("字符%c,%d个\n",s[i][0],j);
			//	printf("n1 = %d,n2 = %d\n",num[j][0],num[j][1]);
				if(les > num[j][num[j][3]]){//当前最小大于其他最大 dc > ab  3 > 2 
					ncorrect = 1;
					//cout << "ENTER 1   " << les << "  " << num[j][num[j][3]] << endl;
					break;
				}else if(les == num[j][num[j][3]]){//==
					if(tha >= num[j][num[j][2]]){//另一个大于另一个 bc ==/> ab 2 == 2/3 > 1
						ncorrect = 1;  
						//cout <<"ENTER 2   " << tha << "  " << num[j][num[j][2]] << endl;
						break;
					}
				}
			}
			if(ncorrect == 1) ans.push_back(0);
			else ans.push_back(1);
			ncorrect = 0;
		}
		for(int i = 0;i <= (int)ans.size()-1;i++)
			cout << ans[i];
	}else if(m == 1){
		les = 1e9;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < m;j++)
				cin >> s[i][j];
			les = min(les,ma[s[i][0]]);
		}
		for(int i = 1;i <= n;i++){
			if(ma[s[i][0]] == les) ans.push_back(1);
			else ans.push_back(0);
		}
		for(int i = 0;i <= (int)ans.size()-1;i++)
			cout << ans[i];
	}
	return 0;
}
