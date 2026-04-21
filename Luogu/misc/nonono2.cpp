#include <bits/stdc++.h>
using namespace std;
int n,s;
bool p(int n){
    for (int i=2;i<=int(sqrt(n));i++)
        if (n%i==0) return false;
        return true;
}
int main(){
    int i,j;
    cin>>n;
    for (i=4;i<=n;i++)
        for (j=2;j<=i/2;j++)
        if (i%2!=0) break;
        else if (p(j)&&p(i-j)){
		    cout<<i<<"="<<j<<"+"<<i-j<<endl;
	    	break;
		}
    return 0;
}
