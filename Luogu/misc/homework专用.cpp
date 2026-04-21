#include<iostream>
using namespace std;
class a{
	char p;
};
int main(){
    
}

/*
   int a;
	float s;
	cin >> a;
	if(a <= 150){
		s = a*0.4463;
	}else if(a >= 151 && a <= 400){
		s = (a - 150)*0.4663 + 150*0.4463;
	}else if(a >400){
		s = 150*0.4463 + (400 - 151)*0.4663 + (a - 400)*0.5663;
	}
	printf("%.1f",s);
*/

/*
int L,M;
int cnt=0;
int vis[10000+10];
int main()
{
    memset(vis,0,sizeof(vis));
    cin>>L>>M;
    for(int i=0;i<=L;i++)
        vis[i]=0;
    for(int i=1;i<=M;i++)
    {
        int head,tail;
        cin >> head >> tail;
        for(int j=head;j<=tail;j++)
            if(vis[j]==0) vis[j]=1;
    }
    for(int i=0;i<=L;i++)
    {
        if(vis[i]==0)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
*/
/*
#include <stdio.h>
int main ()
{
int i,n,m=-1,k=0;
double j,sum=0.0;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
m=-m;
j=m/(double)(k+1);
sum=sum+j;
k++;
}
printf("%.4lf\n",sum);
return 0;
} 
*/
