//-4713 - 1582*10*4 2299525 ds
//1582*10*5 - 10*14 10ds
//1582*10*14 - 1583  
//1582*10*15 - ? 
//  > 2299535 noBC   days-2299552 = 1583 ~ ?
//  <= 2299535 BC    4year=1461ds
//1461 ds Ò»Èò  Ã¿400years-1  400: 146099ds
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mon[30]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sum[30],T;
ll ri;
bool check(int x){
	if(x<0) return ((-x)%4==1);
	if(x<=1582) return x%4==0;
	return ((x%4==0&&x%100!=0)||(x%400==0));
}
ll cy(int year){
	if(year<0){
		int cnt=year+4713+1;
		return 1ll*cnt*365+ceil(cnt/4.0);
	}
	else if(year<1582){
		return cy(-1)+year*365+year/4;
	}
	else if(year==1582){
		return cy(1581)+355; 
	}
	else if(year==1583){
		return cy(1581)+355+365;
	}
	else if(year<=1600){
		int cnt=year-1583;
		return cy(1583)+cnt*365+(cnt-1)/4+1;
	}
	else{
		int cnt=year-1600;
		return cy(1600)+1ll*cnt*365+cnt/4-cnt/100+cnt/400;
	}
}
int count_month(int year,int month){
	return sum[month]+(check(year)&&(month>=2))-(year==1582&&month>=10)*10;
}
int main(){
	for(int i = 1;i <= 12;i++) sum[i]=sum[i-1]+mon[i];
	cin >> T;
	while(T--){
		cin >> ri;
		ri++;
		int L,R,mid,Year,Month,Day; 
		L=-4713,R=1e9+5;
		while(L<=R){ 
			mid=(L+R)/2;
			if(cy(mid)>=ri) Year=mid,R=mid-1;
			else L=mid+1;
		}
		ri-=cy(Year-1);
		for(int i = 1;i <= 12;i++){
			int cm=count_month(Year,i);
			if(cm>=ri){
				Month=i;
				Day=ri-count_month(Year,i-1);
				break;
			}
		}
		if(Year==1582&&Month==10&&Day>4) Day+=10;
		if(Year<0) printf("%d %d %d BC\n",Day,Month,-Year);
		else printf("%d %d %d\n",Day,Month,Year);
	}
	return 0;
}
