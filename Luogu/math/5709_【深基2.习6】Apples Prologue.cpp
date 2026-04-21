#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,t,s;
    cin>>m>>t>>s;
	if (t == 0){
    	cout << 0;
    	return 0;
	}
    int d =s/t;
    int e = m -d;
    
    if(m==0||t==0||e<=0)
    {
        cout<<"0";
    }else
    {
        if(s%t==0)
        {
            cout<<m-d;
        }else
        {
            cout<<m-d-1;
        }
    }
    return 0;
}
