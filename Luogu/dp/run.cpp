#include <bits/stdc++.h>// 8pts 12:30
using namespace std;
struct expactation{
	double value;
	int length;
} ex[1000001];
int day[1000001];
int c,t,n,m,k,d,x,y,v,dp[1000001],cnt,ans,f,ll;
bool cmp(expactation x,expactation y){
	return x.value > y.value;
}
int main(){
	//freopen("run.in","r",stdin);
	//freopen("run.out","w",stdout);
	cin >> c >> t;
	while(t--){
		f = 0;
		cin >> n >> m >> k >> d;
		if(n >= 100000 && m > 1000) f = 1;
		for(int i = 1;i <= m;i++){
			cin >> x >> y >> v;
			if(f == 1) ans+=v,ll+=y;
			if(f != 1)
				for(int j = x;j >=x-y+1;j--)
					day[j] = max(day[j],v);
		}
		if(f == 1){//sp B
			long long aannss = 0;
			aannss = ans-ll*d;
			cout << aannss <<endl;
			f = 0;
			continue;
		}
		//for(int i = 1;i <= n;i++) cout << day[i] << " " ;
		//cout << endl;
		for(int i = 1;i <= n;i++)
			if(day[i] != 0){
				ex[++cnt].value+=day[i];
				for(int j = i;j <= n;j++){
					if(day[j] != day[j+1]){
						ex[cnt].length = j-i+1;
						ex[cnt].value/=(double)ex[cnt].length;
						i = j;
						break;
					} 
				}
			}
		for(int i = 1;i <= cnt;i++)
			if(ex[i].length > k) ex[i].value = 0;
		sort(ex+1,ex+cnt,cmp);
		for(int i = 1;i <= cnt;i++){
			if(n-ex[i].length <= 0) break;
			ans+=ex[i].value*ex[i].length;
		//	cout << ans << endl;
			n-=ex[i].length;
			ans-=ex[i].length*d;
		//	cout << ex[i].length << endl;
		}
		cout << ans;
	}
	return 0;
}
//һ�ж�����һ��ʢ��ģ���ͬϷ���������н����� 
//                                    ����ܽ����˹ 
//"��ѽ��������������˵�ʱ�䲻�����ء�
//�����������������ʱ����Ҳ����Щ���־��ء�
//��������������Ψһ�Ĺ�ͬ���˰ɡ�
//...�ټ�����ά���أ�ϣ����ϲ����������������Ϸ�ݡ� 
//(������������棬�����貽��)
//......
//...�ң�������й���ά���أ��ٴ�����㵤�����е������� 
//(�����������ᣬ����������)
//...һֱ�������������ˣ�ܽ���ȡ� 
//�����Ϊһ�����࣬�úõػ���ȥ�ɡ� 
//                                      �����������貽���� 
//���ˣ�Ļ�������Ļ��ܽ����˹������̨... 
//                FIN                                    

