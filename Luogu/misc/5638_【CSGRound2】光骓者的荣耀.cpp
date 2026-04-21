#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001],k,Max,now,total;
int main() 
{
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a[i];
		total+=a[i];
	}
	if(k==0){
		cout<<total;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
	Max+=a[i];
	now+=a[i];
	}
	for(int i=2;i<=n-k;i++)
	{
		now=now-a[i-1]+a[i+k-1];
		Max=max(Max,now);
	}
	cout<<total-Max<<endl;
	return 0; 
}
