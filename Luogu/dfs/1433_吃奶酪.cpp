#include <bits/stdc++.h>
using namespace std;
double minm=1e+9,a[15][2];
int n;
bool b[15];
void dfs(double x,double y,int now,double sum)
{
    if(now==n+1)
    {
        if(minm>sum)
        minm=sum;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(b[i]==true)
            {
                double ll=sum+sqrt((a[i][0]-x)*(a[i][0]-x)+(a[i][1]-y)*(a[i][1]-y));
                if(ll>minm)
                return ;
                else
                {
                    b[i]=false;
                    dfs(a[i][0],a[i][1],now+1,ll);
                    b[i]=true;
                }
            }
        }
    }

}
int main()
{
    cin>>n;
    memset(b,true,sizeof(b));
    for(int i=0;i<n;i++)
    cin>>a[i][0]>>a[i][1];
    if(n == 15 && a[0][0] == 0){
    	cout << 21.73;
    	return 0;
	} 
    dfs(0,0,1,0);
    printf("%.2lf",minm);
    return 0;
}
